#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2010, M = 10010;
int n, m;
struct Edge {
    int a, b, w;
    bool operator<(const Edge &t) const {
        return w < t.w;
    }
} e[M];
int p[N];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int t, a, b, w;
        cin >> t >> a >> b >> w;
        if (t == 1) {
            res += w;
            p[find(a)] = find(b);
        } else e[cnt++] = {a, b, w};
    }

    sort(e, e + cnt);

    for (int i = 0; i < cnt; i++) {
        int pa = find(e[i].a), pb = find(e[i].b);
        if (pa != pb) {
            p[pa] = pb;
            res += e[i].w;
        }
    }

    cout << res << endl;

    return 0;
}