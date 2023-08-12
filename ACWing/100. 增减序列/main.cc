#include <iostream>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = n; i > 1; i--) a[i] -= a[i - 1];

  ll pos = 0, neg = 0;
  for (int i = 2; i <= n; i++)
    if (a[i] > 0) pos += a[i];
    else neg -= a[i];
  
  printf("%lld\n", min(pos, neg) + abs(pos - neg));
  printf("%lld\n", abs(pos - neg) + 1);
}