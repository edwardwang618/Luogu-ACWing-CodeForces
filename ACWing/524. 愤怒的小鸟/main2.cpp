#include <iostream>
#include <cstring>
#include <cmath>

#define x first
#define y second
using namespace std;

const int N = 20, M = 1 << 20;
const double eps = 1e-8;
int n, m;
int path[N][N], f[M];
pair<double, double> q[20];

// s是已经覆盖了多少小猪的状态的二进制表示，返回的是至少还要多少个抛物线可以覆盖所有小猪
int dfs(int s) {
    if (f[s] != -1) return f[s];
    if (s == (1 << n) - 1) return f[s] = 0;

    // 找到第一个未覆盖的小猪的下标，赋值给t
    int t = 0;
    for (int i = 0; i < n; i++)
        if (!(s >> i & 1)) {
            t = i;
            break;
        }

    int res = 0x3f3f3f3f;
    // 枚举与小猪t配对的另一个小猪的下标，构造抛物线覆盖之
    for (int i = 0; i < n; i++) {
        int c = 0;
        if (i <= t) c = path[i][t];
        else c = path[t][i];

        // 只要覆盖小猪t和i的抛物线是存在的，那么它一定能覆盖t，
        // 也就一定能使得s向递归出口更进一步），则枚举之
        if (c) res = min(res, dfs(c | s) + 1);
    }

    return f[s] = res;
}

// 将path[i][j]初始化为能覆盖小猪i和j的抛物线能覆盖的所有小猪的状态；
// 因为path[i][j] = path[j][i]，我们只计算i <= j的情况
void init_paths() {
    // 枚举抛物线覆盖的第一只小猪
    for (int i = 0; i < n; i++) {
        // 有可能存在某个点，必须得单独由一条抛物线来覆盖它，
        // 那么这种抛物线只覆盖小猪i，所以它的path值为1 << i
        path[i][i] = 1 << i;
        // 枚举覆盖的第二只小猪。j = i的情况已经在上一行枚举过
        for (int j = i + 1; j < n; j++) {
            double x1 = q[i].x, y1 = q[i].y, x2 = q[j].x, y2 = q[j].y;
            // 同一竖线上的两个点无法被同一条抛物线穿过，略过此种情况
            if (fabs(x1 - x2) < eps) continue;
            double a = (y1 / x1 - y2 / x2) / (x1 - x2), b = y1 / x1 - a * x1;
            // 略过开口向上的抛物线
            if (a >= 0) continue;
            // 计算此抛物线能覆盖的小猪的状态。首先它一定能覆盖小猪i和j
            int s = (1 << i) | (1 << j);
            for (int k = 0; k < n; k++) {
                // 略过已经被覆盖的i和j
                if (k == i || k == j) continue;
                double x = q[k].x, y = q[k].y;
                // 如果能覆盖小猪k，则计入状态
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

        memset(f, -1, sizeof f);
        cout << dfs(0) << endl;
    }

    return 0;
}