#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
int a[10];
bool vis[10];
vector<int> v;

void dfs() {
  if (v.size() == n) {
    for (int x : v) printf("%d ", x);
    puts("");
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (vis[i] || i > 1 && a[i] == a[i - 1] && !vis[i - 1]) continue;
    vis[i] = true;
    v.push_back(a[i]);
    dfs();
    vis[i] = false;
    v.pop_back();
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  dfs();
}