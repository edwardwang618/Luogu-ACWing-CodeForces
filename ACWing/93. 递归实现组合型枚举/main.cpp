#include <iostream>
using namespace std;

int n, m;
int a[30];

void dfs(int u, int m, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) cout << a[i] << ' ';
        cout << endl;
    }

    for (int i = u; i <= n; i++) {
        a[cnt] = i;
        dfs(i + 1, m, cnt + 1);
    }
}

int main() {
    cin >> n >> m;

    dfs(1, m, 0);
    return 0;
}