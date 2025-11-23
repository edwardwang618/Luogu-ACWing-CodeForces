#include <iostream>
using namespace std;

const int N = 10;
int n, a[N];
bool used[N];

void dfs(int u) {
  if (u == n + 1) {
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (used[i]) continue;
    a[u] = i;
    used[i] = true;
    dfs(u + 1);
    used[i] = false;
  }
}

int main() {
  scanf("%d", &n);
  dfs(1);
}