#include <iostream>
using namespace std;

const int N = 30;
int n;
int a[N];
int f[N][N], g[N][N];

void dfs(int l, int r) {
    if (l > r) return;
    int root = g[l][r];
    cout << root << ' ';
    dfs(l, root - 1);
    dfs(root + 1, r);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int len = 1; len <= n; len++) 
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (len == 1) {
                f[l][l] = a[l];
                g[l][l] = l;
            } else {
                for (int k = l; k <= r; k++) {
                    int x = k == l ? 1 : f[l][k - 1];
                    int y = k == r ? 1 : f[k + 1][r];
                    int s = x * y + a[k];
                    if (f[l][r] < s) {
                        f[l][r] = s;
                        g[l][r] = k;
                    }
                }
            }
        }

    cout << f[1][n] << endl;
    dfs(1, n);

    return 0;
}