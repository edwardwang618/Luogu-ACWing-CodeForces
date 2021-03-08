#include <iostream>
#include <vector>
using namespace std;

const int N = 11, M = 1 << 10;
int n, m;
int g[110];
vector<int> state;
int f[2][M][M];
int cnt[M];

bool check(int st) {
    for (int i = 0; i < m; i++)
        if ((st >> i & 1) && ((st >> i + 1 & 1) || (st >> i + 2 & 1)))
            return false;
    return true;
}

int count(int st) {
    int res = 0;
    while (st) {
        st -= st & -st;
        res++;
    }

    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            if (x == 'H') g[i] += 1 << j;
        }
    
    for (int i = 0; i < 1 << m; i++)
        if (check(i)) {
            state.push_back(i);
            cnt[i] = count(i);
        }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < state.size(); j++)
            for (int k = 0; k < state.size(); k++)
                for (int u = 0; u < state.size(); u++) {
                    if (i == 1 && u != 0 && j != 0) continue;
                    int a = state[j], b = state[k], c = state[u];
                    if ((a & b) | (b & c) | (a & c)) continue;
                    if (g[i - 1] & a | g[i] & b) continue;
                    f[i & 1][j][k] = max(f[i & 1][j][k], f[i - 1 & 1][u][j] + cnt[b]);
                }

    int res = 0;
    for (int j = 0; j < state.size(); j++)
        for (int k = 0; k < state.size(); k++)
            res = max(res, f[n & 1][j][k]);

    cout << res << endl;

    return 0;
}