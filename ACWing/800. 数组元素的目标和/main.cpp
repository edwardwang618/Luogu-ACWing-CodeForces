#include <iostream>
using namespace std;

const int N = 100010;
int n, m, x;
int a[N], b[N];

int main() {
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    int i = 0, j = m - 1;
    while (a[i] + b[j] != x) {
        int s = a[i] + b[j];
        if (s > x) j--;
        else i++;
    }

    cout << i << ' ' << j << endl;

    return 0;
}