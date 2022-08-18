#include <iostream>
#include <cstring>
#include <cmath>

#define x first
#define y second
using namespace std;

typedef pair<int, int> PII;

const int N = 160;
const double INF = 1e20;
int n;
PII q[N];
char g[N][N];
double d[N][N], maxd[N];

double get_dist(PII a, PII b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &q[i].x, &q[i].y);

    for (int i = 0; i < n; i++) cin >> g[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j) {
                if (g[i][j] == '0') d[i][j] = INF;
                else d[i][j] = get_dist(q[i], q[j]);
            }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            if (d[i][j] < INF)
                maxd[i] = max(maxd[i], d[i][j]);

    double res1 = 0;
    for (int i = 0; i < n; i++)
        res1 = max(res1, maxd[i]);

    double res2 = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (d[i][j] >= INF)
                res2 = min(res2, get_dist(q[i], q[j]) + maxd[i] + maxd[j]);

    printf("%lf\n", max(res1, res2));

    return 0;
}