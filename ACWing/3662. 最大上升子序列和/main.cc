#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
int n, a[N];
long tr[N];
vector<int> xs;
long f[N];

int get(int x) {
  return lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
}

int lowbit(int x) {
  return x & -x;
}

void add(int x, long v) {
  for (int i = x; i <= n; i += lowbit(i))
    tr[i] = max(tr[i], v);
}

long query(int x) {
  long res = 0;
  for (int i = x; i; i -= lowbit(i))
    res = max(res, tr[i]);
  
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    xs.push_back(a[i]);
  }

  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());

  long res = 0;
  for (int i = 1; i <= n; i++) {
    int k = get(a[i]);
    f[i] = query(k - 1) + a[i];
    res = max(res, f[i]);
    add(k, f[i]);
  }

  printf("%ld\n", res);
}