#include <iostream>
using namespace std;

const int N = 16, M = 3010;
int n, m;
int a[N];
long f[M];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];

    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = a[i]; j <= m; j++)
            f[j] += f[j - a[i]];

    cout << f[m] << endl;

    return 0;
}