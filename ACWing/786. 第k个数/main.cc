#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, k, a[N];

int quick_select(int l, int r, int k) {
  if (l >= r) return a[l];
  int i = l, j = r, piv = a[l + r >> 1];
  while (i <= j) {
    while (a[i] < piv) i++;
    while (a[j] > piv) j--;
    if (i <= j) swap(a[i++], a[j--]);
  }

  if (k <= j) return quick_select(l, j, k);
  else if (k >= i) return quick_select(i, r, k);
  return a[k];
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  printf("%d\n", quick_select(1, n, k));
}