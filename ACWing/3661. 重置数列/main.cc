#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, k;
int a[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    int res = n;
    for (int x = 1; x <= 100; x++) {
      int cnt = 0;
      for (int i = 1; i <= n; i++)
        if (a[i] != x) {
          cnt++;
          i += k - 1;
        }

      res = min(res, cnt);
    }

    printf("%d\n", res);
  }
}