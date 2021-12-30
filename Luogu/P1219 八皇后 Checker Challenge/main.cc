#include <iostream>
using namespace std;

const int N = 15;
int n, a[N];
bool col[N], diag[2 * N], udiag[2 * N];
int cnt;

void dfs(int u) {
    if (u == n) {
        cnt++;
        if (cnt <= 3) {
            for (int i = 0; i < n; i++)
                printf("%d ", a[i] + 1);
            puts("");
        }
        
        return;
    }

    for (int i = 0; i < n; i++) {
        if (col[i] || diag[i + u] || udiag[i - u + n - 1]) continue;
        a[u] = i;
        col[i] = diag[i + u] = udiag[i - u + n - 1] = true;
        dfs(u + 1);
        col[i] = diag[i + u] = udiag[i - u + n - 1] = false;
    }
}

int main() {
    scanf("%d", &n);
    dfs(0);
    printf("%d\n", cnt);

    return 0;
}