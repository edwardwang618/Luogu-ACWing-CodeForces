#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010, M = 2 * N;
int n, res;
int h[N], e[M], ne[M], w[M], idx;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u, int parent) {
    int dist = 0;
    int d1 = 0, d2 = 0;

    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == parent) continue;

        int d = dfs(j, u) + w[i];
        dist = max(dist, d);

        if (d >= d1) d2 = d1, d1 = d;
        else if (d > d2) d2 = d;
    }

    res = max(res, d1 + d2);

    return dist;
}

int main() {
    memset(h, -1, sizeof h);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c); 
    }

    dfs(1, -1);
    cout << res << endl;

    return 0;
}