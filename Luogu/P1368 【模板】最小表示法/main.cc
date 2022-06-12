#include <iostream>
#include <cstring>
using namespace std;

const int N = 6e5 + 10;
int n;
int a[N];

int get() {
  int i = 0, j = 1, k;
  while (i < n && j < n) {
    k = 0;
    while (i + k < n && j + k < n && a[i + k] == a[j + k]) k++;
    if (k == n) break;
    a[i + k] > a[j + k] ? i += k + 1 : j += k + 1;
    if (i == j) j++;
  }

  return min(i, j);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  memcpy(a + n, a, (n - 1) * sizeof(int));
  int idx = get();
  for (int i = idx; i < idx + n; i++) printf("%d ", a[i]);
}