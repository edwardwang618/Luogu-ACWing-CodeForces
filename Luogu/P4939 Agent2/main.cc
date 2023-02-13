#include <iostream>
using namespace std;

const int N = 1e7 + 10;
int n, m;
int tr[N];

#define lowbit(x) (x & -x)

void add(int k, int x) {
  for (int i = k; i <= n; i += lowbit(i)) tr[i] += x;
}

int sum(int k) {
  int res = 0;
  for (int i = k; i; i -= lowbit(i)) res += tr[i];
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int op, a, b;
    scanf("%d", &op);
    if (!op) {
      scanf("%d%d", &a, &b);
      add(b + 1, -1);
      add(a, 1);
    } else {
      scanf("%d", &a);
      printf("%d\n", sum(a));
    }
  }
}