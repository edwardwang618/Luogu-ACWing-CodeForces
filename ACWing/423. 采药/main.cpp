#include <iostream>
using namespace std;

const int N = 1010, M = 110;
int f[N];
int w[M], v[M];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) cin >> w[i] >> v[i];

    for (int i = 1; i <= m; i++)
        for (int j = n; j >= 0; j--)
            if (j >= w[i]) f[j] = max(f[j], f[j - w[i]] + v[i]);
            
    cout << f[n] << endl;

    return 0;
}