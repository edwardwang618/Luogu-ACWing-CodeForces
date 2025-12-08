#include <iostream>
using namespace std;

using ll = long long;

int main() {
  ll a, b, p;
  scanf("%lld%lld%lld", &a, &b, &p);

  ll res = 1 % p;
  while (b) {
    if (b & 1) res = res * a % p;
    a = a * a % p;
    b >>= 1;
  }
  printf("%lld\n", res);
}