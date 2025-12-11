#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

struct Point {
  ll x, y;
};

Point get(ll n, ll a) {
  if (!n)
    return {0, 0};
  ll block = 1ll << 2 * n - 2, len = 1ll << n - 1;
  auto p = get(n - 1, a % block);
  ll x = p.x, y = p.y;

  int z = a / block;
  if (!z)
    return {y, x};
  else if (z == 1)
    return {x, y + len};
  else if (z == 2)
    return {x + len, y + len};
  else
    return {len * 2 - 1 - y, len - 1 - x};
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    ll n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);
    auto pa = get(n, a - 1), pb = get(n, b - 1);
    double dx = pa.x - pb.x, dy = pa.y - pb.y;
    printf("%.0lf\n", sqrt(dx * dx + dy * dy) * 10);
  }
}