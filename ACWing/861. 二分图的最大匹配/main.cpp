#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int v) {
    st[v] = true;
    for (int i = h[v]; ~i; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = true;
            if (match[j] == 0 || dfs(match[j])) {
                match[j] = v;
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin >> n1 >> n2 >> m;

    memset(h, -1, sizeof h);

    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    int res = 0;
    for (int i = 1; i <= n1; i++) {
        memset(st, false, sizeof st);
        if (dfs(i)) res++;
    }

    cout << res << endl;

    return 0;
}