#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
const ll INF = 5e18;
int n;
struct Point {
  ll x, y;
  bool operator<(const Point& p) const { return x != p.x ? x < p.x : y < p.y; }
} p[N];
int b[N];
#define sqr(x) ((x) * (x))
ll dis(int l, int r) { return sqr(p[l].x - p[r].x) + sqr(p[l].y - p[r].y); }

void merge(int l, int r) {
  static Point tmp[N];
  int mid = l + (r - l >> 1), i = l, j = mid + 1, k = l;
  while (i <= mid && j <= r)
    if (p[i].y <= p[j].y)
      tmp[k++] = p[i++];
    else
      tmp[k++] = p[j++];
  while (i <= mid) tmp[k++] = p[i++];
  while (j <= r) tmp[k++] = p[j++];
  for (i = l; i <= r; i++) p[i] = tmp[i];
}

ll dfs(int l, int r) {
  if (l >= r) return INF;

  int mid = l + (r - l >> 1), cnt = 0;
  ll t = p[mid].x;
  ll d = min(dfs(l, mid), dfs(mid + 1, r));
  merge(l, r);
  for (int i = l; i <= r; i++)
    if (sqr(p[i].x - t) < d) b[++cnt] = i;
  for (int i = 1; i <= cnt; i++)
    for (int j = i + 1; j <= cnt && (p[b[j]].y - p[b[i]].y) < d; j++)
      d = min(d, dis(b[i], b[j]));
  return d;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld%lld", &p[i].x, &p[i].y);
  sort(p + 1, p + 1 + n);
  printf("%.4lf\n", sqrt(dfs(1, n)));
}