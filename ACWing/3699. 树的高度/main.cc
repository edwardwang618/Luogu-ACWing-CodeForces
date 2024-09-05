#include <cstring>
#include <iostream>
using namespace std;

const int N = 10010, M = N << 1;
int n;
int root;
int h[N], e[M], ne[M], idx;
int q[N];
bool vis[N];

#define add(a, b) e[idx] = b, ne[idx] = h[a], h[a] = idx++

int bfs() {
  int res = 0;
  int hh = 0, tt = 1;
  q[hh] = root;
  vis[root] = true;

  while (hh < tt) {
    for (int i = tt - hh; i; i--) {
      int t = q[hh++];
      for (int j = h[t]; ~j; j = ne[j]) {
        int v = e[j];
        if (!vis[v]) {
          q[tt++] = v;
          vis[v] = true;
        }
      }
    }
    if (hh < tt) res++;
  }
  return res;
}

int main() {
  scanf("%d%d", &n, &root);
  memset(h, -1, sizeof h);
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  printf("%d\n", bfs());
}