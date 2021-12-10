#include <iostream>
using namespace std;

const int N = 1010, M = N * (N - 1) / 2;
int n, m, k;
int p[N], x[M], y[M];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) scanf("%d%d", &x[i], &y[i]);
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) p[j] = j;
        int cur;
        scanf("%d", &cur);
        int cnt = n - 1;
        for (int j = 1; j <= m; j++) {
            if (x[j] == cur || y[j] == cur) continue;
            int px = find(x[j]), py = find(y[j]);
            if (px != py) {
                p[px] = py;
                cnt--;
            }
        }

        printf("%d\n", cnt - 1);
    }

    return 0;
}