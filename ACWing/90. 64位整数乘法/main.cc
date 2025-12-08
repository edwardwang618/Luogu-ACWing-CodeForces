#include <iostream>
using namespace std;

using ll = long long;

ll qadd(ll a, ll b, ll p) {
  ll res = 0;
  while (b) {
    if (b & 1) res = (res + a) % p;
    b >>= 1;
    a = (a + a) % p;
  }

  return res;
}

int main() {
  ll a, b, p;
  scanf("%lld%lld%lld", &a, &b, &p);
  printf("%lld\n", qadd(a, b, p));
}