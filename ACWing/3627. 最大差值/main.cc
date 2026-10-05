#include <iostream>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int n, k, a[N];

int main() {
  int T;
  scanf("%d", &T);
  auto quick_select = [&](int k) {
    int l = 1, r = n;
    while (l < r) {
      int i = l, j = r, piv = a[i + j >> 1];
      while (i <= j) {
        while (a[i] > piv) i++;
        while (a[j] < piv) j--;
        if (i <= j) swap(a[i++], a[j--]);
      }
      if (k <= j) r = j;
      else if (k >= i) l = i;
      else return;
    }
  };
  while (T--) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    quick_select(k + 1);
    ll res = 0;
    for (int i = 1; i <= k + 1; i++) res += a[i];
    printf("%lld\n", res);
  }  
}