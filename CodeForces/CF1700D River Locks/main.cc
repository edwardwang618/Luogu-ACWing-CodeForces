#include <iostream>
using namespace std;
using LL = long long;
 
const int N = 2e5 + 10;
int n, q;
LL a[N], low;
 
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    a[i] += a[i - 1];
  }
 
  for (int i = 1; i <= n; i++) low = max(low, (a[i] + i - 1) / i);
 
  scanf("%d", &q);
  while (q--) {
    long t;
    scanf("%lld", &t);
    if (t < low) puts("-1");
    else printf("%lld\n", (a[n] + t - 1) / t);
  }
}
