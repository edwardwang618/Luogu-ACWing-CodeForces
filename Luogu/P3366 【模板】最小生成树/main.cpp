#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5010, M = 2e5 + 10;
int n, m;
struct Edge {
    int a, b, w;
    bool operator<(const Edge & t) const {
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
    for (int i = 0; i < m; i++)
        cin >> e[i].a >> e[i].b >> e[i].w;

    sort(e, e + m);

    for (int i = 1; i <= n; i++) p[i] = i;

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int px = find(e[i].a), py = find(e[i].b);
        if (px != py) {
            p[px] = py;
            res += e[i].w;
            cnt++;
        }
    }

    if (cnt < n - 1) cout << "orz" << endl;
    else cout << res << endl;

    return 0;
}