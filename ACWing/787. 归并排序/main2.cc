#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N], tmp[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  for (int k = 1; k < n; k <<= 1)
    for (int l = 0; l + k < n; l += k << 1) {
      int i = l, j = l + k, idx = l, r = min(l + (k << 1) - 1, n - 1);
      while (i < l + k && j <= r) {
        if (a[i] <= a[j]) tmp[idx++] = a[i++];
        else tmp[idx++] = a[j++];
      }

      while (i < l + k) tmp[idx++] = a[i++];
      while (j <= r) tmp[idx++] = a[j++];

      for (idx = l; idx <= r; idx++) a[idx] = tmp[idx];
    }

  for (int i = 0; i < n; i++) printf("%d ", a[i]);
}