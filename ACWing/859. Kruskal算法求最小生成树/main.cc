#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
int n, m, idx;
struct Edge {
  int u, v, w;
} e[M];
int p[N];

int find(int x) {
  return x == p[x] ? x : p[x] = find(p[x]);
}

bool merge(int a, int b) {
  int pa = find(a), pb = find(b);
  if (pa == pb) return false;
  p[pa] = pb;
  return true;
}

int kruskal() {
  int res = 0, cnt = 0;
  sort(e + 1, e + idx + 1, [&](auto& w1, auto& w2) { return w1.w < w2.w; });
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 1; i <= idx; i++) {
    auto [u, v, w] = e[i];
    if (merge(u, v)) {
      res += w;
      cnt++;
    }
  }

  return cnt == n - 1 ? res : INF;
}

int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == b) continue;
    e[++idx] = {a, b, c};
  }

  int res = kruskal();
  res == INF ? puts("impossible") : printf("%d\n", res);
}