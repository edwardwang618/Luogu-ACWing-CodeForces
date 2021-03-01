#include <iostream>
using namespace std;

const int N = 110, M = 10010;
int a[N];
int f[M];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= a[i]; j--)
            f[j] += f[j - a[i]];

    cout << f[m] << endl;

    return 0;
}