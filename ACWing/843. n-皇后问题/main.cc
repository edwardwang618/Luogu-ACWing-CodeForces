#include <iostream>
using namespace std;

const int N = 10;
int n;
int res[N];
bool col[N], diag[2 * N], udiag[2 * N];

void dfs(int u) {
  if (u == n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        if (res[i] == j) putchar('Q');
        else putchar('.');
      puts("");
    }

    puts("");
    return;
  }

  for (int i = 0; i < n; i++) {
    // (u, i)
    // x - y = n - 1 - k
    if (col[i] || diag[u + i] || udiag[n - 1 - (u - i)]) continue;
    col[i] = diag[u + i] = udiag[n - 1 - (u - i)] = true;
    res[u] = i;
    dfs(u + 1);
    col[i] = diag[u + i] = udiag[n - 1 - (u - i)] = false;
  }
}

int main() {
  scanf("%d", &n);
  dfs(0);
}