#include <iostream>
#include <algorithm>
using namespace std;

const int N = 210;
string s[N];
int n;

bool check(int len) {
    string t = s[0].substr(0, len);
    for (int i = 1; i < n; i++) 
        for (int j = 0; j < len; j++)
            if (s[i][j] != t[j]) return false;
    return true;
}

int main() {
    while (cin >> n, n) {
        int r = 0x3f3f3f3f;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            reverse(s[i].begin(), s[i].end());
            r = min(r, (int) s[i].size());
        }

        int l = 0;
        while (l < r) {
            int mid = l + (r - l + 1 >> 1);
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        string res = s[0].substr(0, l);
        reverse(res.begin(), res.end());
        cout << res << endl;
    }

    return 0;
}