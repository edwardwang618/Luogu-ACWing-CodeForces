#include <iostream>
#include <cstring>
using namespace std;

const int N = 30;
int n;
int din[N], dout[N], p[N];
bool st[N];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    string s;

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(din, 0, sizeof din);
        memset(dout, 0, sizeof dout);
        memset(st, 0, sizeof st);
        for (int i = 0; i < 26; i++) p[i] = i;

        for (int i = 0; i < n; i++) {
            cin >> s;
            int a = s[0] - 'a', b = s[s.size() - 1] - 'a';
            st[a] = st[b] = true;
            dout[a]++, din[b]++;

            p[find(a)] = find(b);
        }

        int start = 0, end = 0;

        bool res = true;
        for (int i = 0; i < 26; i++) {
            if (din[i] != dout[i]) {
                if (din[i] == dout[i] + 1) end++;
                else if (din[i] + 1 == dout[i]) start++;
                else {
                    res = false;
                    break;
                }
            }
        }    

        if (res && !(start == 0 && end == 0 || start == 1 && end == 1)) res = false;

        int parent = -1;
        for (int i = 0; i < 26; i++)
            if (st[i]) {
                if (parent == -1) parent = find(i);
                else if (parent != find(i)) {
                    res = false;
                    break;
                }
            }
        
        cout << (res ? "Ordering is possible." : "The door cannot be opened.") << endl;
    }

    return 0;
}