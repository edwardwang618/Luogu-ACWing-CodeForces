#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010, M = 2 * N;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int v, int c) {
    color[v] = c;
    for (int i = h[v]; i != -1; i = ne[i]) {
        int j = e[i];
        if (color[j] == c) return false;
        if (color[j] == -1 && !dfs(j, c ^ 1)) return false; 
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    memset(h, -1, sizeof h);
    memset(color, -1, sizeof color);

    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    bool res = true;
    for (int i = 1; i <= n; i++) 
        if (color[i] == -1 && !dfs(i, 0)) {
            res = false;
            break;
        }

    cout << (res ? "Yes" : "No") << endl;

    return 0;
}