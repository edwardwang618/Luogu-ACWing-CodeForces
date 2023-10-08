#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int n, m;
ll a[N];
ll prea[N], preb[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) prea[i] = prea[i - 1] + a[i];
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) preb[i] = preb[i - 1] + a[i];
  scanf("%d", &m);
  while (m--) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    ll *x = op == 1 ? prea : preb;
    printf("%lld\n", x[r] - x[l - 1]);
  }
}