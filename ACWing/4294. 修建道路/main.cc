#include <algorithm>
#include <iostream>
using namespace std;

const int N = 110;
int n, m, q;
int p[N];
struct Edge {
  int x, y, len;
} e[N * N / 2];
int res;

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    for (int j = 1; j <= n; j++) {
      int len;
      scanf("%d", &len);
      if (j > i) e[++m] = {i, j, len};
    }
  }

  scanf("%d", &q);
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[find(x)] = find(y);
  }

  sort(e + 1, e + 1 + m, [&](auto& e1, auto& e2) { return e1.len < e2.len; });

  for (int i = 1; i <= m; i++) {
    int x = e[i].x, y = e[i].y, len = e[i].len;
    int px = find(x), py = find(y);
    if (px == py) continue;
    res += len;
    p[px] = py;
  }

  printf("%d\n", res);
}