/*
 * @lc app=leetcode id=2158 lang=cpp
 *
 * [2158] Amount of New Area Painted Each Day
 */

// @lc code=start
#if 0
class Solution {
public:
  struct Node {
    int l, r;
    int len;
    bool tag;
  };

  vector<Node> tr;
  vector<int> xs;

  int len(int u) { return tr[u].r - tr[u].l + 1; }
  void pushup(int u) { tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len; }
  void pushdown(int u) {
    if (tr[u].tag) {
      auto &l = tr[u << 1], &r = tr[u << 1 | 1];
      l.tag = r.tag = true;
      l.len = len(u << 1);
      r.len = len(u << 1 | 1);
      tr[u].tag = false;
    }
  }

  void build(int u, int l, int r) {
    tr[u] = {l, r, 0, false};
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
  }

  int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].len;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if (l <= mid) res += query(u << 1, l, r);
    if (r > mid) res += query(u << 1 | 1, l, r);
    return res;
  }

  void modify(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
      tr[u].len = len(u);
      tr[u].tag = true;
      return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, r);
    if (r > mid) modify(u << 1 | 1, l, r);
    pushup(u);
  }

  vector<int> amountPainted(vector<vector<int>> &ps) {
    int l = 5e4, r = 0;
    for (auto &p : ps) l = min(l, p[0]), r = max(r, p[1] - 1);
    int n = r - l + 1;
    tr.resize(n << 2);
    build(1, l, r);
    vector<int> res;
    res.reserve(ps.size());
    for (auto &p : ps) {
      int len = p[1] - p[0], l = p[0], r = p[1] - 1;
      res.push_back(len - query(1, l, r));
      modify(1, l, r);
    }
    return res;
  }
};
#endif
class Solution {
public:
  vector<int> amountPainted(vector<vector<int>> &ps) {
    vector<int> p(5e4 + 2);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    vector<int> res;
    res.reserve(ps.size());
    for (auto &w : ps) {
      int cnt = 0;
      for (int i = find(w[0]); i < w[1]; i = find(i)) {
        p[i] = i + 1;
        cnt++;
      }
      res.push_back(cnt);
    }
    return res;
  }
};
// @lc code=end