#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, a[N], tmp[N];

void merge_sort() {
  for (int k = 1; k < n; k <<= 1) 
    for (int l = 1; l + k <= n; l += k * 2) {
      int i = l, j = l + k, r = min(l + 2 * k - 1, n), idx = l;
      while (i <= l + k - 1 && j <= r)
        if (a[i] <= a[j]) tmp[idx++] = a[i++];
        else tmp[idx++] = a[j++];
      while (i <= l + k - 1) tmp[idx++] = a[i++];
      while (j <= r) tmp[idx++] = a[j++];

      for (i = l; i <= r; i++) a[i] = tmp[i];
    }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  merge_sort();
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
}