#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N], mp[N];
int f[N];

int bin_search(int r, int x) {
  int l = 1;
  while (l < r) {
    int mid = l + (r - l >> 1);
    if (f[mid] >= x) r = mid;
    else l = mid + 1;
  }

  return f[l] >= x ? l : -1;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    mp[a[i]] = i;
  }
  int idx = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    x = mp[x];

    if (!idx || x > f[idx]) f[++idx] = x;
    else {
      int p = bin_search(idx, x);
      if (~p) f[p] = x;
      else f[++idx] = x;
    }
  }

  printf("%d\n", idx);
}