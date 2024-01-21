#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int N = 110;
int n;
unordered_map<int, vector<int>> g;
unordered_map<int, int> ind;
int q[N];

int topsort() {
  int res = 0;
  int hh = 1, tt = 1;
  for (auto &[k, v] : g)
    if (!ind[k]) q[tt++] = k;
  while (hh < tt) {
    int t = q[hh++];
    res++;
    for (auto &ne : g[t])
      if (g.count(ne) && !--ind[ne]) q[tt++] = ne;
  }
  return n - res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, m;
    scanf("%d%d", &x, &m);
    g[x].reserve(0);
    for (int j = 1; j <= m; j++) {
      int y;
      scanf("%d", &y);
      g[x].push_back(y);
    }
  }
  for (auto &[k, v] : g)
    for (int x : v)
      if (g.count(x)) ind[x]++;

  int res = topsort();
  if (!res)
    puts("YES");
  else
    printf("%d\n", res);
}