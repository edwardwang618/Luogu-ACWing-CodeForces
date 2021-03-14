#include <iostream>
#include <cstring>
using namespace std;

const int N = 50010, M = 2 * N;
int n;
int h[N], e[M], ne[M], idx;
int sum[N];
bool is_root[N];
int res;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u) {
    int d1 = 0, d2 = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];

        int dist = dfs(j) + 1;
        if (dist > d1) d2 = d1, d1 = dist;
        else if (dist > d2) d2 = dist;
    }

    res = max(res, d1 + d2);

    return d1;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= n / i; j++)
            sum[i * j] += i;

    memset(h, -1, sizeof h);
    memset(is_root, true, sizeof is_root);

    for (int i = 2; i <= n; i++)
        if (i > sum[i]) {
            add(sum[i], i);
            is_root[i] = false;
        }

    for (int i = 1; i <= n; i++)
        if (is_root[i])
            dfs(i);

    cout << res << endl;

    return 0;
}