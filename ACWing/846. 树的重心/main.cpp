#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010, M = 2 * N;
int n;
int h[N], e[M], ne[M], idx;
int res;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u, int from) {
  int cnt = 1, ms = 0;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v != from) {
      int s = dfs(v, u);
      if (!s) return 0;
      ms = max(ms, s);
      cnt += s;
    }
  }

  ms = max(ms, n - cnt);
  if (ms <= n / 2) {
    res = ms;
    return 0;
  }

  return cnt;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  dfs(1, -1);
  printf("%d\n", res);
}