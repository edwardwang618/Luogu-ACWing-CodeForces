#include <iostream>
using namespace std;

using ll = long long;

const int N = 1e5 + 10;
int n, a[N], tmp[N];

ll merge_sort(int l, int r) {
  if (l >= r) return 0;
  int mid = l + r >> 1;
  ll res = merge_sort(l, mid) + merge_sort(mid + 1, r);
  int i = l, j = mid + 1, idx = l;
  while (i <= mid && j <= r)
    if (a[i] <= a[j]) tmp[idx++] = a[i++], res += j - mid - 1;
    else tmp[idx++] = a[j++]; 
  while (i <= mid) tmp[idx++] = a[i++], res += r - mid;
  while (j <= r) tmp[idx++] = a[j++];
  for (i = l; i <= r; i++) a[i] = tmp[i];
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  printf("%lld\n", merge_sort(1, n));
}