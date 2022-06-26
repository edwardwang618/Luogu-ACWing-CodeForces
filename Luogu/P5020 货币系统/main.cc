#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110, M = 25010;
int n, a[N];
bool f[M];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);

    memset(f, 0, sizeof f);
    f[0] = true;

    int res = 0;
    for (int i = 1; i <= n; i++) {
      if (!f[a[i]]) res++;
      for (int j = 0; j <= a[n] - a[i]; j++)
        f[j + a[i]] |= f[j];
    }

    printf("%d\n", res);
  }
}