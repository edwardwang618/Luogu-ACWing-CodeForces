#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, a[N];

void quick_sort(int l, int r) {
  if (l >= r) return;
  int piv = a[l + r >> 1];
  int i = l, j = r;
  while (i <= j) {
    while (a[i] < piv) i++;
    while (a[j] > piv) j--;
    if (i <= j) swap(a[i++], a[j--]);
  }
  quick_sort(l, j), quick_sort(i, r);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  quick_sort(1, n);
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
}