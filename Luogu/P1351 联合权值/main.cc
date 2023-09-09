#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e5 + 10, M = N * 2, MOD = 10007;
int n;
int h[N], e[M], ne[M], idx;
int w[N];

#define add(a, b) e[idx] = b, ne[idx] = h[a], h[a] = idx++

int main() {
  memset(h, -1, sizeof h);

  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);

  int max_res = 0, sum_res = 0;
  for (int u = 1; u <= n; u++) {
    int max1 = -1, max2 = -1, sum = 0, sum_sqr = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
      int v = e[i];
      if (w[v] > max1)
        max2 = max1, max1 = w[v];
      else if (w[v] > max2)
        max2 = w[v];

      sum = (sum + w[v]) % MOD;
      sum_sqr = (sum_sqr + w[v] * w[v]) % MOD;
    }

    if (max2 == -1) continue;
    sum_res = (sum_res + sum * sum - sum_sqr) % MOD;
    max_res = max(max_res, max1 * max2);
  }

  printf("%d %d\n", max_res, sum_res);
}