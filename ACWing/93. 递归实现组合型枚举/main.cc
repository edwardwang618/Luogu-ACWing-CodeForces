#include <iostream>
using namespace std;

int n, m;

void dfs(int u, int cnt, int st) {
  if (cnt == m) {
    for (int i = 0; i < n; i++)
      if (st >> i & 1) printf("%d ", i + 1);
    puts("");
    return;
  }

  for (int i = u; i <= n + 1 + cnt - m; i++) {
    st ^= 1 << i - 1;
    dfs(i + 1, cnt + 1, st);
    st ^= 1 << i - 1;
  }
}

int main() {
  scanf("%d%d", &n, &m);
  dfs(1, 0, 0);
}