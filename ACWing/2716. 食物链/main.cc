#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
int n, m;
int h[N], e[M], ne[M], idx;
int ind[N], outd[N];
int f[N];
bool is_end[N];

#define add(a, b) e[idx] = b, ne[idx] = h[a], h[a] = idx++

int bfs() {
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (!ind[i]) {
      q.push(i);
      f[i] = 1;
    } else if (!outd[i])
      is_end[i] = true;

  int res = 0;
  while (q.size()) {
    auto t = q.front();
    q.pop();
    if (is_end[t]) res += f[t];
    for (int i = h[t]; ~i; i = ne[i]) {
      int v = e[i];
      f[v] += f[t];
      if (!--ind[v]) q.push(v);
    }
  }
  return res;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b);
    ind[b]++, outd[a]++;
  }
  printf("%d\n", bfs());
}