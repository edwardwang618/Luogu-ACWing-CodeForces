#include <iostream>
using namespace std;

int n, m;
int a[30];

void dfs(int u, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) cout << a[i] << ' ';
        cout << endl;
        return;
    }

    for (int i = u; i <= n + 1 + cnt - m; i++) {
        a[cnt] = i;
        dfs(i + 1, cnt + 1);
    }
}

int main() {
    cin >> n >> m;

    dfs(1, 0);
    return 0;
}