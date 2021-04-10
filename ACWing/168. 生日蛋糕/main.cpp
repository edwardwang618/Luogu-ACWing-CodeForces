#include <iostream>
#include <cmath>
using namespace std;

const int N = 10010, M = 22;
int n, m;
int minv[M], mins[M];
int R[M], H[N];
int res = 0x3f3f3f3f;

void dfs(int u, int v, int s) {
    if (v + minv[u] > n) return;
    if (s + mins[u] >= res) return;

    if (s + 2 * (n - v) / R[u + 1] >= res) return;

    if (!u) {
        if (v == n) res = s;
        return;
    }

    for (int r = min(R[u + 1] - 1, (int) sqrt(n - v)); r >= u; r--) 
        for (int h = min(H[u + 1] - 1, (n - v) / r / r); h >= u; h--) {
            int t = 0;
            if (u == m) t = r * r;

            R[u] = r, H[u] = h;
            dfs(u - 1, v + r * r * h, s + 2 * r * h + t);
        }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        minv[i] = minv[i - 1] + i * i * i;
        mins[i] = mins[i - 1] + 2 * i * i;
    }

    R[m + 1] = H[m + 1] = res;

    dfs(m, 0, 0);

    printf("%d\n", res == 0x3f3f3f3f ? 0 : res);

    return 0;
}