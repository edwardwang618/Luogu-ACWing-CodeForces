#include <iostream>
using namespace std;

const int N = 1010;
string s, t;
int n, m;
int f[N][N];

int main() {
    cin >> n >> m;
    cin >> s >> t;

    s = ' ' + s;
    t = ' ' + t;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            if (s[i] == t[j]) f[i][j] = 1 + f[i - 1][j - 1];
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]);

    cout << f[n][m] << endl;

    return 0;
}