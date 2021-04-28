#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 6010;
int n;
struct Edge {
    int a, b, w;
    bool operator<(const Edge & e) const {
        return w < e.w;
    }
} e[N];
int p[N], sz[N];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            e[i] = {a, b, w};
        }

        sort(e, e + n - 1);

        for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;

        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            int pa = find(p[e[i].a]), pb = find(p[e[i].b]);
            if (pa != pb) {
                res += (sz[pa] * sz[pb] - 1) * (e[i].w + 1);
                p[pa] = pb;
                sz[pb] += sz[pa];
            }
        }

        cout << res << endl;
    }

    return 0;
}