#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, a[N], tmp[N];

void merge_sort(int l, int r) {
  if (l >= r) return;
  int mid = l + r >> 1;
  merge_sort(l, mid), merge_sort(mid + 1, r);
  int i = l, j = mid + 1, k = l;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) tmp[k++] = a[i++];
    else tmp[k++] = a[j++];
  }
  while (i <= mid) tmp[k++] = a[i++];
  while (j <= r) tmp[k++] = a[j++];
  for (k = l; k <= r; k++) a[k] = tmp[k];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  merge_sort(1, n);
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
}