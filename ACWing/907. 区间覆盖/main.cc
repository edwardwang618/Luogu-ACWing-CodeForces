#include <algorithm>
#include <iostream>
using namespace std;

const int N = 100010;

struct Range {
  int l, r;
  bool operator<(const Range &W) const { return l < W.l; }
} range[N];

int main() {
  int st, ed;
  scanf("%d%d", &st, &ed);

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &range[i].l, &range[i].r);

  sort(range, range + n);

  int res = 0, r = 0;
  for (int i = 0; i < n; i++) {
    r = -2e9;
    int j = i;
    while (j < n && range[j].l <= st) r = max(r, range[j++].r);
    i = j - 1;

    if (r < st) break;

    res++;
    if (r >= ed) break;

    st = r;
  }

  printf("%d\n", r >= ed ? res : -1);
}