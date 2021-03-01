#include <iostream>
using namespace std;

const int N = 1010, M = 20010;
int n, m;
int v[N], w[N], s[N];
int f[N][M];
int q[M];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) 
        // v体积，w价值，s个数
        cin >> v[i] >> w[i] >> s[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < v[i]; j++) {
            int hh = 0, tt = 0;
            for (int k = j; k <= m; k += v[i]) {  
                f[i][k] = f[i - 1][k];  
                if (hh < tt && q[hh] < k - s[i] * v[i]) hh++;
                
                if (hh < tt) 
                    f[i][k] = max(f[i][k], f[i - 1][q[hh]] + (k - q[hh]) / v[i] * w[i]);

                while (hh < tt && f[i - 1][q[tt - 1]] - (q[tt - 1] - j) / v[i] * w[i] <= f[i - 1][k] - (k - j) / v[i] * w[i])
                    tt--; 

                q[tt++] = k;
            }
        }
    }

    cout << f[n][m] << endl;

    return 0;
}