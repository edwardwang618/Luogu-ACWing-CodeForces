#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N], tmp[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  for (int k = 0; 1 << k < n; k++)
    for (int l = 0; l + (1 << k) < n; l += 1 << k + 1) {
      int i = l, j = l + (1 << k), idx = l, r = min(l + (1 << k + 1), n);
      while (i < l + (1 << k) && j < r) {
        if (a[i] <= a[j]) tmp[idx++] = a[i++];
        else tmp[idx++] = a[j++];
      }

      while (i < l + (1 << k)) tmp[idx++] = a[i++];
      while (j < r) tmp[idx++] = a[j++];

      for (idx = l; idx < r; idx++) a[idx] = tmp[idx];
    }

  for (int i = 0; i < n; i++) printf("%d ", a[i]);
}