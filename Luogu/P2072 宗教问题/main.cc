#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;
int n, m, k;
int a[N], f[N];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  int res = 1;
  for (int i = 1, cnt = 0, st = 0; i <= n; i++) {
    if (st >> a[i] & 1) continue;
    if (cnt < k) {
      st |= 1 << a[i];
      cnt++;
    } else {
      st = 1 << a[i];
      cnt = 1;
      res++;
    }
  }

  memset(f, 0x3f, sizeof f);
  f[0] = 0;
  for (int i = 1, cnt = 0, st = 0; i <= n; i++) {
    cnt = st = 0;
    for (int j = i; j; j--) {
      if (!(st >> a[j] & 1)) {
        cnt++;
        st |= 1 << a[j];
      }
      if (cnt > k) break;
      f[i] = min(f[i], f[j - 1] + cnt);
    }
  }

  printf("%d\n%d\n", res, f[n]);
}