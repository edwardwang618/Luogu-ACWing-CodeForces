#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10, M = N << 1;
int n, m;
int h[N], e[M], ne[M], idx;
int col[N];

#define add(a, b) \
  e[idx] = b, ne[idx] = h[a], h[a] = idx++

bool bfs(int u, int c) {
  queue<int> q;
  q.push(u);
  col[u] = c;
  while (q.size()) {
    int u = q.front(); q.pop();
    for (int i = h[u]; ~i; i = ne[i]) {
      int v = e[i];
      if (col[v] == col[u]) return false;
      if (!~col[v]) {
        col[v] = col[u] ^ 1;
        q.push(v);
      }
    }
  }

  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  memset(h, -1, sizeof h);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  bool res = true;
  memset(col, -1, sizeof col);
  for (int i = 1; i <= n; i++)
    if (!~col[i] && !bfs(i, 0)) {
      res = false;
      break;
    }
  
  puts(res ? "Yes" : "No");
}