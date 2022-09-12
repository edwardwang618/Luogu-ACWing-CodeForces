#include <iostream>
using namespace std;

const int N = 100010;
int n;
int a[N], tmp[N];

void merge_sort(int l, int r) {
  if (l >= r) return;

  int m = l + (r - l >> 1);
  merge_sort(l, m), merge_sort(m + 1, r);

  int k = l, i = l, j = m + 1;
  while (i <= m && j <= r) {
    if (a[i] <= a[j]) tmp[k++] = a[i++];
    else tmp[k++] = a[j++];
  }

  while (i <= m) tmp[k++] = a[i++];
  while (j <= r) tmp[k++] = a[j++];

  for (i = l; i <= r; i++) a[i] = tmp[i];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  merge_sort(0, n - 1);
  for (int i = 0; i < n; i++) printf("%d ", a[i]);
}