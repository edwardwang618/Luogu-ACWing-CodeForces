#include <iostream>
using namespace std;
using ll = long long;

const int N = 5e5 + 10;
int n;
int a[N], b[N];

ll merge_sort(int l, int r) {
  ll res = 0;
  if (l >= r) return res;
  int mid = l + r >> 1;
  res += merge_sort(l, mid) + merge_sort(mid + 1, r);
  int i = l, j = mid + 1, idx = l;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j])
      b[idx++] = a[i++];
    else
      res += mid - i + 1, b[idx++] = a[j++];
  }
  while (i <= mid) b[idx++] = a[i++];
  while (j <= r) b[idx++] = a[j++];
  for (int i = l; i <= r; i++) a[i] = b[i];
  return res;
}

int main() {
  while (scanf("%d", &n) && n) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    printf("%lld\n", merge_sort(1, n));
  }
}