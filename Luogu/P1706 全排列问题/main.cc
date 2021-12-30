#include <iostream>
using namespace std;

const int N = 10;
int n;
int a[N];
bool vis[N];

void dfs(int u) {
    if (u == n + 1) {
        for (int i = 1; i <= n; i++)
            printf("%5d", a[i]);
        puts("");
        return;
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            a[u] = i;
            vis[i] = true;
            dfs(u + 1);
            vis[i] = false;
        }
}

int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}