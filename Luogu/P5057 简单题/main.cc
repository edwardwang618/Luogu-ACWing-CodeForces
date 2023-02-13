#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int tr[N];

int lowbit(int x) {
  return x & -x;
}

void add(int k, int x) {
  for (; k <= n; k += lowbit(k)) tr[k] ^= x;
}

int sum(int k) {
  int res = 0;
  for (; k; k -= lowbit(k)) res ^= tr[k];
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int t, l, r, k;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d", &l, &r);
      add(r + 1, 1), add(l, 1);
    } else {
      scanf("%d", &k);
      printf("%d\n", sum(k));
    }
  }
}