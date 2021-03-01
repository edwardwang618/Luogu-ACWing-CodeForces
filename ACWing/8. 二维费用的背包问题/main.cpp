#include <iostream>
using namespace std;

const int N = 1010, S = 110;
int n, V, M;
int v[N], m[N], w[N];
int f[S][S];

int main() {
    cin >> n >> V >> M;
    for (int i = 1; i <= n; i++) cin >> v[i] >> m[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = V; j >= 0; j--)
            for (int k = M; k >= 0; k--) {
                if (j >= v[i] && k >= m[i])
                    f[j][k] = max(f[j][k], f[j - v[i]][k - m[i]] + w[i]);
            }

    cout << f[V][M] << endl;

    return 0;
}