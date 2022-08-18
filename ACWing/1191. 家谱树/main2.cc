#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 110, M = N * N;
int n, m;
int h[N], e[M], ne[M], idx;
bool vis[N];
vector<int> res;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    vis[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!vis[v]) dfs(v);
    }

    res.push_back(u);
}

int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) {
        int s;
        while (cin >> s, s) add(i, s);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i]) dfs(i);
    
    for (int i = n - 1; i >= 0; i--)
        printf("%d ", res[i]);

    return 0;
}