#include <iostream>
using namespace std;

const int N = 5e5 + 10;
int n, m, len;
int son[N][2], idx;
int cnt[N], cnt_down[N];
int u;

int query() {
  int res = 0, p = 0;
  scanf("%d", &len);
  while (len--) {
    scanf("%d", &u);
    if (son[p][u])
      p = son[p][u];
    else {
      while (len--) scanf("%d", &u);
      return res;
    }
    res += cnt[p];
  }
  res += cnt_down[p] - cnt[p];
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  while (n--) {
    scanf("%d", &len);
    int p = 0;
    while (len--) {
      scanf("%d", &u);
      if (!son[p][u]) son[p][u] = ++idx;
      p = son[p][u];
      cnt_down[p]++;
    }
    cnt[p]++;
  }

  while (m--) printf("%d\n", query());
}