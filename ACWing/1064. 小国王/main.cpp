#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 11, M = 1 << 10, K = 110;
int n, k;
vector<int> state;
int cnt[M];
vector<int> head[M];
long f[N][K][M];

bool check(int st) {
    for (int i = 0; i < n; i++)
        if ((st >> i & 1) && (st >> i + 1 & 1))
            return false;
    return true;
}

int count(int st) {
    int cnt = 0;
    while (st) {
        st -= st & -st;
        cnt++;
    }
    return cnt;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < 1 << n; i++)
        if (check(i)) {
            state.push_back(i);
            cnt[i] = count(i);
        }

    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++) {
            int a = state[i], b = state[j];
            if ((a & b) == 0 && check(a | b))
                head[i].push_back(j);
        }

    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            for (int cu = 0; cu < state.size(); cu++)
                for (auto pr : head[cu]) {
                    int c = cnt[state[cu]];
                    if (c <= j) f[i][j][cu] += f[i - 1][j - c][pr];
                }

    long res = 0;
    for (int i = 0; i < 1 << n; i++) res += f[n][k][i];

    cout << res << endl;

    return 0;
}