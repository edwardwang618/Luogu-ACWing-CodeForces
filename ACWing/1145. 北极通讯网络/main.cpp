#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 510, M = N * N / 2;
int n, k, m;
struct Edge {
    int a, b;
    double w;
    bool operator<(const Edge &e) const {
        return w < e.w;
    }
} e[M];
int p[N];
PII a[M];

double get_dist(PII a, PII b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            e[m++] = {i, j, get_dist(a[i], a[j])};

    sort(e, e + m);

    for (int i = 0; i < n; i++) p[i] = i;

    double res = 0;
    int cnt = n;
    for (int i = 0; i < m; i++) {
        if (cnt <= k) break;

        int pa = find(e[i].a), pb = find(e[i].b);
        if (pa != pb) {
            p[pa] = pb;
            cnt--;
            res = e[i].w;
        }
    }

    printf("%.2lf\n", res);

    return 0;
}