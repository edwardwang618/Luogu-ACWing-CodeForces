#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010;
int n, m;
int w[N], v[N];
int f[N];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = w[i]; j <= m; j++)
            f[j] = max(f[j], f[j - w[i]] + v[i]);

    cout << f[m] << endl;

    return 0;
}