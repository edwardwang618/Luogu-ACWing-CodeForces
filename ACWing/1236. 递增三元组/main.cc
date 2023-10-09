#include <iostream>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int n;
int b[N];
int pa[N], pb[N], pc[N];

int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    pa[x]++;
  }
  for (int i = 1, x; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    pb[x]++;
  }

  for (int i = 1; i < N - 2; i++) pa[i] += pa[i - 1];
  for (int i = N - 2; i >= 0; i--) pb[i] += pb[i + 1];

  ll res = 0;
  for (int i = 1; i <= n; i++) {
    ll l = b[i] ? pa[b[i] - 1] : 0, r = pb[b[i] + 1];
    res += l * r;
  }

  printf("%lld\n", res);
}