#include <iostream>
using namespace std;

int a[10010];

int main() {
    int l, m;
    scanf("%d%d", &l, &m);
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x]++, a[y + 1]--;
    }

    for (int i = 1; i <= l; i++) a[i] += a[i - 1];
    int res = 0;
    for (int i = 0; i <= l; i++) if (!a[i]) res++;

    printf("%d\n", res);

    return 0;
}