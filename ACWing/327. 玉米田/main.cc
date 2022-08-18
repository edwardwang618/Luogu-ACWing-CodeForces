#include <iostream>
#include <vector>
using namespace std;

const int N = 15, M = 1 << 12, mod = 1e8;
int n, m;
int a[N], f[N][M];
vector<int> state, head[M];

bool check(int st) {
    for (int i = 0; i < n - 1; i++)
        if ((st >> i & 1) && (st >> i + 1 & 1))
            return false;

    return true;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < n; j++) {
            int s;
            cin >> s;
            a[i] += !s << j;
        }

    for (int i = 0; i < 1 << n; i++)
        if (check(i))
            state.push_back(i);

    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++) {
            int a = state[i], b = state[j];
            if (!(a & b)) head[i].push_back(j);
        }

    f[0][0] = 1;
    for (int i = 1; i <= m; i++)
        for (int cur = 0; cur < state.size(); cur++)
            for (int prev : head[cur])
                if (!(state[cur] & a[i]))
                    f[i][cur] = (f[i][cur] + f[i - 1][prev]) % mod;
    
    int res = 0;
    for (int i = 0; i < state.size(); i++) res = (res + f[m][i]) % mod;

    cout << res << endl;

    return 0;
}