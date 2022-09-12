#include <iostream>
using namespace std;

const int N = 100010;
int n, q, k;
int a[N];

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  int x, y;
  while (q--) {
    cin >> k;
    int l = 0, r = n - 1;
    while (l < r) {
      int m = l + (r - l >> 1);
      if (a[m] >= k) r = m;
      else l = m + 1;
    }

    if (a[l] != k) {
      puts("-1 -1");
      continue;
    }

    x = l;
    l = 0, r = n - 1;
    while (l < r) {
      int m = l + (r - l + 1 >> 1);
      if (a[m] <= k) l = m;
      else r = m - 1;
    }
    y = l;
    printf("%d %d\n", x, y);
  }
}