#include <iostream>
#include <algorithm>
using namespace std;

const int N = 30010;
int a[N];
bool vis[N];
int w, n;

int main() {
  scanf("%d%d", &w, &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  int res = 0;
  for (int i = 1, j = n; i <= n; i++) {
    if (vis[i]) continue;
    while (i < j && (vis[j] || a[i] + a[j] > w)) j--;
    vis[i] = vis[j] = true;
    res++;
  }

  printf("%d\n", res);
}