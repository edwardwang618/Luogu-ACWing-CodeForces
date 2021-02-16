#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010, M = 2 * N;

int n, m;
int p[N];

struct Edge {
    int a, b, w;
    bool operator<(const Edge &W) const {
        return w < W.w;
    }
} edges[M];

void init(int n) {
    for (int i = 0; i < n; i++) p[i] = i;
}

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
} 

bool merge(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return false;
    p[px] = py;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    
    init(n);
    sort(edges, edges + m);

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        if (merge(a, b)) {
            res += w;
            cnt++;
        }
    }

    if (cnt < n - 1) cout << "impossible" << endl;
    else cout << res << endl;

    return 0;
}