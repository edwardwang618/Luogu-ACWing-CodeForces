#include <iostream>
using namespace std;

const int N = 100010;
int a[N], b[N];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    int i = 0;
    for (int j = 0; i < n && j < m; j++)
        if (a[i] == b[j]) i++;

    cout << (i == n ? "Yes" : "No") << endl;

    return 0;
}