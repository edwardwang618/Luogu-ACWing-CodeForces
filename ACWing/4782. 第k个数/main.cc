#include <iostream>
using namespace std;

int n, k;
int a[1010];

int quick_select(int l, int r, int k) {
  if (l >= r) return a[l];
  int i = l, j = r, piv = a[l + r >> 1];
  while (i <= j) {
    while (a[i] < piv) i++;
    while (piv < a[j]) j--;
    if (i <= j) swap(a[i++], a[j--]);
  }

  if (k <= j) return quick_select(l, j, k);
  if (k >= i) return quick_select(i, r, k);
  return a[k];
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  printf("%d\n", quick_select(1, n, n - k + 1));
}