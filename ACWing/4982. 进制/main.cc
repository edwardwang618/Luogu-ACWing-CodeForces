#include <iostream>
using namespace std;

using ll = long long;

int main() {
  ll a, b;
  scanf("%lld%lld", &a, &b);
  static auto f = [&](ll x) {
    int res = 0;
    for (int i = 1; i <= 63; i++)
      for (int j = 0; j <= i - 1; j++) {
        ll n = (1 << i + 1) - 1 - (1 << j);
        if (n <= x) res++;
      }
    return res;
  };

  printf("%d\n", f(b) - f(a - 1));
}