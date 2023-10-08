#include <iostream>
using namespace std;
using ll = long long;

int n;

int main() {
  scanf("%d", &n);
  ll res = 0, minp = 2e9;
  for (int i = 1; i <= n; i++) {
    ll p;
    scanf("%lld", &p);
    if (i > 1) res = max(res, p - minp);
    minp = min(minp, p);
  }

  cout << res << endl;
}