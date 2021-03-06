#include <iostream>
#include <string>
using namespace std;

const int N = 55, mod = 1e9 + 7;
int n;
string s;
int f[N][N];

void build_next(string p, int ne[]) {
    ne[0] = -1;
    for (int i = 0, j = -1; i < s.size() - 1;)
        if (j < 0 || p[j] == p[i]) {
            i++;
            j++;
            ne[i] = p[i] != p[j] ? j : ne[j];
        } else j = ne[j];
}

int main() {
    cin >> n;
    cin >> s;

    int ne[s.size()];
    build_next(s, ne);

    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < s.size(); j++)
            for (char ch = 'a'; ch <= 'z'; ch++) {
                int u = j;
                while (u != -1 && ch != s[u]) u = ne[u];
                u++;
                if (u < s.size()) f[i][u] = (f[i][u] + f[i - 1][j]) % mod;
            }

    int res = 0;
    for (int i = 0; i < s.size(); i++) res = (res + f[n][i]) % mod;

    cout << res << endl;

    return 0;
}