#include <iostream>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int n, k;
int cnt[N];

int main() {
  scanf("%d%d", &n, &k);
  ll s = 0, res = 0;
  cnt[0] = 1;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    s = (s + x) % k;
    res += cnt[s];
    cnt[s]++;
  }
  printf("%lld", res);
}