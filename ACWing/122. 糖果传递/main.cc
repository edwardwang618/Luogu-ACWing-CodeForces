#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;
int n;
int a[N];
ll s[N];

int main() {
  scanf("%d", &n);
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  sum /= n;
  for (int i = 1; i <= n; i++) a[i] -= sum;
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  sort(s + 1, s + 1 + n);
  ll res = 0;
  for (int i = 1; i <= n; i++) res += abs(s[i] - s[(n + 1) / 2]);
  printf("%lld\n", res);
}