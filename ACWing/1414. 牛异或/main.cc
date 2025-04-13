#include <iostream>
using namespace std;

const int N = 3e6 + 10;
int tr[N][2], pos[N], idx;
int n;
int res, l, r;

void add(int x, int i) {
  int p = 0;
  for (int j = 20; j >= 0; j--) {
    int c = (x >> j) & 1;
    if (!tr[p][c])
      tr[p][c] = ++idx;
    p = tr[p][c];
  }
  pos[p] = i;
}

void query(int x, int i) {
  int u = 0, p = 0;
  for (int j = 20; j >= 0; j--) {
    int c = (x >> j) & 1;
    if (tr[p][!c]) {
      p = tr[p][!c];
      u |= (1 << j);
    } else
      p = tr[p][c];
  }
  if (!r || u > res) {
    r = i;
    l = pos[p] + 1;
    res = u;
  }
}

int main() {
  scanf("%d", &n);
  int pre_sum = 0;
  add(pre_sum, 0);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    pre_sum ^= x;
    query(pre_sum, i);
    add(pre_sum, i);
  }

  printf("%d %d %d\n", res, l, r);
}