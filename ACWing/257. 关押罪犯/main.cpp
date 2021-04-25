#include <iostream>
#include <cstring>
using namespace std;

const int N = 20010, M = 200010;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int col[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool dfs(int x, int c, int mi) {
    col[x] = c;
    for (int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if (w[i] <= mi) continue;
        else if (col[j] == c) return false;
        else if (col[j] == (c ^ 1)) continue;
        else if (!dfs(j, c ^ 1, mi)) return false;
    }

    return true;
}

bool check(int mi) {
    memset(col, -1, sizeof col);
    for (int i = 1; i <= n; i++)
        if (col[i] == -1) 
            if (!dfs(i, 0, mi)) return false;

    return true;
}

int main() {
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    int r = 0;
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
        r = max(r, c);
    }

    int l = 0;
    while (l < r) {
        int mi = l + (r - l >> 1);
        if (check(mi)) r = mi;
        else l = mi + 1;
    }
    
    printf("%d\n", l);

    return 0;
}