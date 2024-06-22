#include <iostream>
using namespace std;

int n;
int a[1010];

void quick_sort(int l, int r, auto& cmp) {
  if (l >= r) return;
  int i = l, j = r, piv = a[l + r >> 1];
  while (i <= j) {
    while (cmp(a[i], piv)) i++;
    while (cmp(piv, a[j])) j--;
    if (i <= j) swap(a[i++], a[j--]);
  }
  quick_sort(l, j, cmp), quick_sort(i, r, cmp);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  auto cmp = [&](int a, int b) {
    if (a % 2 == b % 2) return a < b;
    return a % 2 != 0;
  };
  quick_sort(1, n, cmp);
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
}