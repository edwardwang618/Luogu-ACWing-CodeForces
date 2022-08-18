#include <iostream>
using namespace std;

const int N = 100010;
int a[N], s[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];

    while (m--) {
        int l, r;
        cin >> l >> r;
        printf("%d\n", s[r] - s[l - 1]);
    }

    return 0;
}