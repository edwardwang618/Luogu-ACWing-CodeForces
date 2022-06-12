#include <iostream>
#include <algorithm>
#define x first
#define y second
using namespace std;
using PII = pair<int, int>;

const int N = 1e5 + 10, INF = 1e9 + 1;
int n;
int p[N], l[N], r[N];
PII a[N], res[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].x);
    a[i].y = i;
  }

  sort(a + 1, a + 1 + n);
  a[0].x = INF, a[n + 1].x = -INF;
  r[0] = 1, l[n + 1] = n;
  for (int i = 1; i <= n; i++) {
    l[i] = i - 1, r[i] = i + 1;
    p[a[i].y] = i;
  }

  for (int i = n; i > 1; i--) {
    int pos = p[i], left = l[pos], right = r[pos];
    int lv = abs(a[pos].x - a[left].x), rv = abs(a[pos].x - a[right].x);
    if (lv < rv) res[i] = {lv, a[left].y};
    else if (lv > rv) res[i] = {rv, a[right].y};
    else res[i] = {lv, a[left].x < a[right].x ? a[left].y : a[right].y};
    r[left] = right, l[right] = left;
  }

  for (int i = 2; i <= n; i++) printf("%d %d\n", res[i].x, res[i].y);
}