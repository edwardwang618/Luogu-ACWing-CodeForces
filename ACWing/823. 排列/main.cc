#include <iostream>
using namespace std;

int n, a[10];
bool vis[10];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) printf("%d ", a[i]);
        puts("");
        return;
    }
    
    for (int i = 1; i <= n; i++) 
        if (!vis[i]) {
            vis[i] = true;
            a[u] = i;
            dfs(u + 1);
            vis[i] = false;
        }
}

int main() {
    cin >> n;
    dfs(0);

    return 0;
}