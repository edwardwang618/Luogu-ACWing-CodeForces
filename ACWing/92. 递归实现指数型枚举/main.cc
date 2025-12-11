#include <iostream>
using namespace std;

int state, n;

void dfs(int u) {
  for (int i = 0; i < n; i++)
    if (state >> i & 1)
      printf("%d ", i + 1);
  puts("");

  for (int i = u; i < n; i++) {
    state ^= 1 << i;
    dfs(i + 1);
    state ^= 1 << i;
  }
}

int main() {
  scanf("%d", &n);
  dfs(0);
}