#include <iostream>
#include <vector>
using namespace std;

int n, vis;

void dfs(int u, auto& v) {
  if (u == n + 1) {
    for (int x : v) printf("%d ", x);
    puts("");
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (vis >> i - 1 & 1) continue;
    v.push_back(i);
    vis ^= 1 << i - 1;
    dfs(u + 1, v);
    vis ^= 1 << i - 1;
    v.pop_back();
  }
}

int main() {
  scanf("%d", &n);
  vector<int> a;
  a.reserve(n);
  dfs(1, a);
}