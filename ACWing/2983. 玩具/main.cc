#include <iostream>
#include <cstring>
#define x first
#define y second
using namespace std;
using PLL = pair<long, long>;

const int N = 5010;
int n, m;
PLL a[N], b[N];
int res[N];

PLL operator-(PLL a, PLL b) {
  return {a.x - b.x, a.y - b.y};
}

long cross(PLL a, PLL b) {
  return a.x * b.y - a.y * b.x;
}

int find(long x, long y) {
  int l = 0, r = n;
  while (l < r) {
    int mid = l + r >> 1;
    if (cross(a[mid] - b[mid], PLL{x, y} - b[mid]) > 0) r = mid;
    else l = mid + 1;
  }

  return l;
}

int main() {
  bool is_first = true;
  while (scanf("%d", &n), n) {
    long x1, y1, x2, y2;
    scanf("%d%ld%ld%ld%ld", &m, &x1, &y1, &x2, &y2);
    for (int i = 0; i < n; i++) {
      long u, l;
      scanf("%ld%ld", &u, &l);
      a[i] = {u, y1}, b[i] = {l, y2};
    }
    a[n] = {x2, y1}, b[n] = {x2, y2};

    if (is_first) is_first = false;
    else puts("");

    memset(res, 0, sizeof res);
    while (m--) {
      long x, y;
      scanf("%ld%ld", &x, &y);
      res[find(x, y)]++;
    }
    
    for (int i = 0; i <= n; i++)
      printf("%d: %d\n", i, res[i]);
  }
}