#include <iostream>
using namespace std;

const int N = 110;
int n, m;
int h;
int e[N], ne[N], idx;

void init() {
    h = -1, idx = 0;
}

void add_head(int b) {
    e[idx] = b, ne[idx] = h, h = idx++;
}

int main() {
    scanf("%d%d", &n, &m);
    init();
    for (int i = n; i >= 1; i--) add_head(i);
    ne[0] = idx - 1;

    int pos = 0;
    while (ne[pos] != pos) {
        for (int i = 0; i < m - 1; i++) pos = ne[pos];
        printf("%d ", e[ne[pos]]);
        ne[pos] = ne[ne[pos]];
    }

    printf("%d\n", e[pos]);
    return 0;
}