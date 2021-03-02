#include <iostream>
using namespace std;

const int N = 30010;
int n, m;
int f[N];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= 0; j--)
            if (j >= v) f[j] = max(f[j], f[j - v] + w * v);
    }

    cout << f[m] << endl;
    
    return 0;
}