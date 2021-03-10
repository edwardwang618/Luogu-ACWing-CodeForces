#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 15, M = 9;
const double INF = 1e8;
int n, m = 8;
int s[N][N];
double f[M][M][M][M][N];
double X;

double get_divn(int x1, int y1, int x2, int y2) {
    double sum = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] - X;
    return sum * sum / n;
}

double dfs(int x1, int y1, int x2, int y2, int k) {
    double &v = f[x1][y1][x2][y2][k];
    if (v >= 0) return v;
    if (k == 1) return v = get_divn(x1, y1, x2, y2);

    v = INF;
    for (int i = x1; i < x2; i++) {
        v = min(v, dfs(x1, y1, i, y2, k - 1) + get_divn(i + 1, y1, x2, y2));
        v = min(v, dfs(i + 1, y1, x2, y2, k - 1) + get_divn(x1, y1, i, y2));
    }

    for (int i = y1; i < y2; i++) {
        v = min(v, dfs(x1, y1, x2, i, k - 1) + get_divn(x1, i + 1, x2, y2));
        v = min(v, dfs(x1, i + 1, x2, y2, k - 1) + get_divn(x1, y1, x2, i));
    }

    return v;
}

int main() {
    cin >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }

    memset(f, -1, sizeof f);
    X = (double) s[m][m] / n;

    printf("%.3lf\n", sqrt(dfs(1, 1, 8, 8, n)));

    return 0;
}