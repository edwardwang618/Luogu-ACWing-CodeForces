#include <iostream>
#include <algorithm>
#include <unordered_map>
#define lowbit(x) (x & -x)
using namespace std;

const int N = 5e5 + 10;
int n, m, a[N], b[N];
int tr[N];
unordered_map<int, int> mp;

void add(int k, int x) {
  for (; k <= n; k += lowbit(k)) tr[k] += x;
}

int sum(int k) {
  int res = 0;
  for (; k; k -= lowbit(k)) res += tr[k];
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }  

  sort(b, b + n);
  m = unique(b, b + n) - b;
  for (int i = 0; i < m; i++) mp[b[i]] = i + 1;

  long res = 0;
  for (int i = n - 1; i >= 0; i--) {
    int x = mp[a[i]];
    res += sum(x - 1);
    add(x, 1);
  }

  printf("%ld\n", res);
}