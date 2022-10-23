#include <cmath>
#include <iostream>
using namespace std;

const int N = 1e4 + 10, M = 500;
int n, m;
int w[N], bel[N];
int len;
int height[M];
struct Query {
  int l, r, h;
} q[N];

void modify(int l, int r, int h) {
  int bl = bel[l], br = bel[r];
  if (bl == br)
    for (int i = l; i <= r; i++) w[i] = max(w[i], h);
  else {
    int i = l, j = r;
    while (bel[i] == bl) w[i] = max(w[i], h), i++;
    while (bel[j] == br) w[j] = max(w[j], h), j--;
    for (int k = bel[i]; k <= bel[j]; k++) height[k] = max(height[k], h);
  }
}

int main() {
  int l, r, h;
  while (cin >> l >> h >> r) {
    q[++m] = {l, r - 1, h};
    n = max(n, q[m].r);
  }

  n++;
  len = sqrt(n);
  for (int i = 1; i <= n; i++) bel[i] = i / len;
  for (int i = 1; i <= m; i++) modify(q[i].l, q[i].r, q[i].h);

  int y = 0;
  for (int i = 1; i <= n; i++)
    if (max(w[i], height[bel[i]]) != y) {
      y = max(w[i], height[bel[i]]);
      printf("%d %d ", i, y);
    }
}