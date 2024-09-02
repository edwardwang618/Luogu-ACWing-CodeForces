#include <iostream>
using namespace std;

const int N = 100010;
int a[N], d[N];
int n, m, l, r, c;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    d[i] = a[i] - a[i - 1];
  }

  while (m--) {
    scanf("%d%d%d", &l, &r, &c);
    d[l] += c;
    d[r + 1] -= c;
  }

  for (int i = 1, s = 0; i <= n; i++) {
    s += d[i];
    printf("%d ", s);
  }
}