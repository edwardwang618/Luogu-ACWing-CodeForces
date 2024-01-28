#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int n, m, k;
int a[N], b[N];

ll calc(int *a, int n) {
  ll res = 0, sum = 0;
  for (int i = 1; i <= n; i++) sum += a[i];
  sum /= n;
  static ll s[N];
  for (int i = 1; i <= n; i++) a[i] -= sum, s[i] = s[i - 1] + a[i];
  sort(s + 1, s + 1 + n);
  for (int i = 1; i <= n; i++) res += abs(s[i] - s[n / 2 + 1]);
  return res;
}

int main() {
  scanf("%d%d%d", &m, &n, &k);
  for (int i = 1; i <= k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x]++, b[y]++;
  }
  if (k % m && k % n)
    puts("impossible");
  else if (k % n)
    printf("row %lld\n", calc(a, m));
  else if (k % m)
    printf("column %lld\n", calc(b, n));
  else
    printf("both %lld\n", calc(a, m) + calc(b, n));
}