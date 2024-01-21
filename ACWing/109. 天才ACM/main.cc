#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;

const int N = 5e5 + 10;
int k;
int n, m;
ll t;
int a[N], b[N], tmp[N];

bool check(int l, int mid, int r) {
  for (int i = mid; i <= r; i++) b[i] = a[i];
  sort(b + mid, b + r + 1);
  int k = l, i = l, j = mid;
  while (i < mid && j <= r)
    if (b[i] <= b[j])
      tmp[k++] = b[i++];
    else
      tmp[k++] = b[j++];
  while (i < mid) tmp[k++] = b[i++];
  while (j <= r) tmp[k++] = b[j++];

  ll sum = 0;
  for (int i = l, j = r; i < j && i < l + m; i++, j--) {
    ll diff = tmp[i] - tmp[j];
    sum += diff * diff;
    if (sum > t) return false;
  }
  for (int i = l; i <= r; i++) b[i] = tmp[i];
  return true;
}

int work() {
  int res = 0;
  int l = 1;
  b[l] = a[l];
  while (l <= n) {
    int p = 1, r = l;
    while (p) {
      // b[l:r]排好序
      if (r + p <= n && check(l, r + 1, r + p))
        r += p, p <<= 1;
      else
        p >>= 1;
    }

    l = r + 1;
    res++;
  }

  return res;
}

int main() {
  scanf("%d", &k);
  while (k--) {
    scanf("%d%d%lld", &n, &m, &t);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    printf("%d\n", work());
  }
}