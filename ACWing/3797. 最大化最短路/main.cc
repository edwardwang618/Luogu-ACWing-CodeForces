#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10, M = 4e5 + 10;
int n, m, k;
int h[N], e[M], ne[M], idx;
int dist1[N], dist2[N], p[N];
int q[N], hh, tt;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int s, int dist[]) {
  memset(dist, 0x3f, N << 2);
  dist[s] = 0;
  int hh = 0, tt = 0;
  q[tt++] = s;
  while (hh < tt) {
    int t = q[hh++];
    for (int i = h[t]; ~i; i = ne[i]) {
      int v = e[i];
      if (dist[v] > dist[t] + 1) {
        dist[v] = dist[t] + 1;
        q[tt++] = v;
      }
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  memset(h, -1, sizeof h);
  for (int i = 0; i < k; i++) scanf("%d", &p[i]);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  bfs(1, dist1), bfs(n, dist2);
  sort(p, p + k, [&](int x, int y) {
    return dist1[x] - dist2[x] < dist1[y] - dist2[y];
  });

  int res = 0, x = dist1[p[0]];
  for (int i = 1; i < k; i++) {
    int t = p[i];
    res = max(res, dist2[t] + x + 1);
    x = max(x, dist1[t]);
  }

  printf("%d\n", min(res, dist1[n]));
}