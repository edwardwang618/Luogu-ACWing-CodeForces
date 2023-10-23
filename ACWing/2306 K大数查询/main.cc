#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int N = 5e4 + 10, P = N * 17 * 17;
int n, m;
vector<int> nums;

struct Query {
  int op, a, b, c;
} q[N];

int find(int x) {
  return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

namespace inner {

struct Node {
#define lc(u) tr[u].lc
#define rc(u) tr[u].rc
  int l, r;
  int lc, rc;
  ll sum, add;
} tr[P];
int idx;

int intersection(int a, int b, int c, int d) {
  return min(b, d) - max(a, c) + 1;
}

void update(int u, int l, int r, int ql, int qr) {
  tr[u].sum += intersection(l, r, ql, qr);
  if (ql <= l && r <= qr) {
    tr[u].add++;
    return;
  }
  int mid = l + r >> 1;
  if (ql <= mid) {
    if (!lc(u)) lc(u) = ++idx;
    update(lc(u), l, mid, ql, qr);
  }
  if (qr > mid) {
    if (!rc(u)) rc(u) = ++idx;
    update(rc(u), mid + 1, r, ql, qr);
  }
}

ll get_cnt(int u, int l, int r, int ql, int qr, int add) {
  if (ql <= l && r <= qr) return tr[u].sum + add * (r - l + 1LL);
  int mid = l + r >> 1;
  ll res = 0;
  add += tr[u].add;
  if (ql <= mid) {
    if (lc(u))
      res += get_cnt(lc(u), l, mid, ql, qr, add);
    else
      res += add * intersection(l, mid, ql, qr);
  }
  if (qr > mid) {
    if (rc(u))
      res += get_cnt(rc(u), mid + 1, r, ql, qr, add);
    else
      res += add * intersection(mid + 1, r, ql, qr);
  }
  return res;
}

}  // namespace inner

namespace outer {
struct Node {
  int l, r;
  int rt;
} tr[N << 2];

void build(int u, int l, int r) {
  tr[u] = {l, r, ++inner::idx};
  if (l == r) return;
  int mid = l + r >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void change(int u, int ql, int qr, int c) {
  inner::update(tr[u].rt, 1, n, ql, qr);
  if (tr[u].l == tr[u].r) return;
  int mid = tr[u].l + tr[u].r >> 1;
  if (c <= mid)
    change(u << 1, ql, qr, c);
  else
    change(u << 1 | 1, ql, qr, c);
}

int query(int u, int ql, int qr, int c) {
  if (tr[u].l == tr[u].r) return tr[u].l;
  int mid = tr[u].l + tr[u].r >> 1;
  ll cnt = inner::get_cnt(tr[u << 1 | 1].rt, 1, n, ql, qr, 0);
  if (cnt >= c)
    return query(u << 1 | 1, ql, qr, c);
  else
    return query(u << 1, ql, qr, c - cnt);
}

}  // namespace outer

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d%d", &q[i].op, &q[i].a, &q[i].b, &q[i].c);
    if (q[i].op == 1) nums.push_back(q[i].c);
  }
  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());
  outer::build(1, 0, nums.size() - 1);
  for (int i = 0; i < m; i++) {
    int op = q[i].op, a = q[i].a, b = q[i].b, c = q[i].c;
    if (op == 1)
      outer::change(1, a, b, find(c));
    else
      printf("%d\n", nums[outer::query(1, a, b, c)]);
  }
}
