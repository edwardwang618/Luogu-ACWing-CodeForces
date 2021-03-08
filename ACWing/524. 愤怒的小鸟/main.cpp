#include <iostream>
#include <cstring>
#include <cmath>

#define x first
#define y second
using namespace std;

const int N = 20, M = 1 << 20;
const double eps = 1e-8;
int n, m;
pair<double, double> q[N];
int path[N][N], f[M];

void init_paths() {
    for (int i = 0; i < n; i++) {
        path[i][i] = 1 << i;
        for (int j = i + 1; j < n; j++) {
            double x1 = q[i].x, y1 = q[i].y, x2 = q[j].x, y2 = q[j].y;
            if (fabs(x1 - x2) < eps) continue;
            double a = (y1 / x1 - y2 / x2) / (x1 - x2), b = y1 / x1 - a * x1;

            if (a >= 0) continue;
            int s = (1 << i) | (1 << j);
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                double x = q[k].x, y = q[k].y;
                if (fabs(a * x * x + b * x - y) < eps) 
                    s += 1 << k;
            }

            path[i][j] = s;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> q[i].x >> q[i].y;

        memset(path, 0, sizeof path);
        init_paths();

        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 0; i < (1 << n) - 1; i++) {
            int t = 0;
            for (int j = 0; j < n; j++)
                if (!(i >> j & 1)) {
                    t = j;
                    break;
                }

            for (int j = 0; j < n; j++) {
                int c = 0;
                if (t <= j) c = path[t][j];
                else c = path[j][t];

                if (c) f[i | c] = min(f[i | c], f[i] + 1);
            }
        }

        cout << f[(1 << n) - 1] << endl;
    }

    return 0;
}