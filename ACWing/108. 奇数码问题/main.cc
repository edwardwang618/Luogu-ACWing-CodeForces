#include <iostream>
using namespace std;
using ll = long long;

const int N = 3e5 + 10;
int n;
int x[N], y[N], b[N];

ll merge_sort(int *a, int l, int r) {
  ll res = 0;
  if (l >= r) return res;
  int mid = l + r >> 1;
  res += merge_sort(a, l, mid) + merge_sort(a, mid + 1, r);
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
  while (~scanf("%d", &n)) {
    for (int i = 1, j = 1; i <= n * n; i++) {
      int c;
      scanf("%d", &c);
      if (c) x[j++] = c;
    }
    for (int i = 1, j = 1; i <= n * n; i++) {
      int c;
      scanf("%d", &c);
      if (c) y[j++] = c;
    }
    n = n * n - 1;
    puts((merge_sort(x, 1, n) % 2 == merge_sort(y, 1, n) % 2) ? "TAK" : "NIE");
  }
}