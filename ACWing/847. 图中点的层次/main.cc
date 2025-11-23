#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
bool vis[N];

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs() {
  if (n == 1) return 0;
  queue<int> q;
  q.push(1);
  vis[1] = true;
  int res = 0;
  while (q.size()) {
    res++;
    for (int i = q.size(); i; i--) {
      int u = q.front(); q.pop();
      for (int j = h[u]; ~j; j = ne[j]) {
        int v = e[j];
        if (!vis[v]) {
          if (v == n) return res;
          vis[v] = true;
          q.push(v);
        }
      }
    }
  }

  return -1;
}

int main() {
  scanf("%d%d", &n, &m);
  memset(h, -1, sizeof h);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == b) continue;
    add(a, b);
  }

  printf("%d\n", bfs());
}