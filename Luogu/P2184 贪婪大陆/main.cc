#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int tr[2][N];

#define lowbit(x) (x & -x)

void add(int i, int k, int x) {
  for (; k <= n; k += lowbit(k)) tr[i][k] += x;
}

int sum(int i, int k) {
  int res = 0;
  for (; k; k -= lowbit(k)) res += tr[i][k];
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int q, l, r;
    scanf("%d%d%d", &q, &l, &r);
    if (q == 1) add(0, l, 1), add(1, r, 1);
    else printf("%d\n", sum(0, r) - sum(1, l - 1));
  }
}