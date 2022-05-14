#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 110, M = N * N;
int n, m;
int c[N], u[N];
int h[N], e[M], ne[M], w[M], idx;
int ind[N], outd[N];

void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void bfs() {
  queue<int> q;
  for (int i = 1; i <= n; i++) 
    if (!ind[i]) q.push(i);

  while (q.size()) {
    int t = q.front(); q.pop();
    for (int i = h[t]; ~i; i = ne[i]) {
      int v = e[i];
      c[v] += c[t] * w[i];
      ind[v]--;
      if (!ind[v]) {
        c[v] = max(0, c[v] - u[v]);
        q.push(v);
      }
    }
  }
}

int main() {
  memset(h, -1, sizeof h);

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &c[i], &u[i]);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    add(x, y, w);
    ind[y]++, outd[x]++;
  }

  bfs();

  bool exists = false;
  for (int i = 1; i <= n; i++)
    if (c[i] > 0 && !outd[i]) {
      exists = true;
      printf("%d %d\n", i, c[i]);
    }
  
  if (!exists) puts("NULL");
}