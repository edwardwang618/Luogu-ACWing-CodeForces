/*
 * @lc app=leetcode id=699 lang=cpp
 *
 * [699] Falling Squares
 */

// @lc code=start
class Solution {
public:
  vector<int> fallingSquares(vector<vector<int>> &ps) {
    vector<int> q;
    for (auto &p : ps) {
      int l = p[0], r = p[0] + p[1] - 1;
      q.push_back(l);
      q.push_back(r);
      p[0] = l, p[1] = r;
    }

    sort(q.begin(), q.end());
    int n = q.erase(unique(q.begin(), q.end()), q.end()) - q.begin();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) mp[q[i]] = i + 1;
    
    struct Node {
      int l, r;
      int max, tag;
    };
    vector<Node> tr(n << 2);
    auto pushup = [&](int u) {
      tr[u].max = max(tr[u << 1].max, tr[u << 1 | 1].max);
    };
    auto pushdown = [&](int u) {
      if (tr[u].tag) {
        int &tag = tr[u].tag;
        tr[u << 1].max = tr[u << 1 | 1].max = tag;
        tr[u << 1].tag = tr[u << 1 | 1].tag = tag;
        tag = 0;
      }
    };
    auto build = [&](this auto &&build, int u, int l, int r) -> void {
      tr[u] = {l, r, 0, 0};
      if (l == r) return;
      int mid = l + r >> 1;
      build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
      pushup(u);
    };
    auto modify = [&](this auto &&modify, int u, int l, int r, int x) -> void {
      if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].max = tr[u].tag = x;
        return;
      }
      pushdown(u);
      int mid = tr[u].l + tr[u].r >> 1;
      if (l <= mid) modify(u << 1, l, r, x);
      if (r > mid) modify(u << 1 | 1, l, r, x);
      pushup(u);
    };
    auto query = [&](this auto &&query, int u, int l, int r) -> int {
      if (l <= tr[u].l && tr[u].r <= r) return tr[u].max;
      pushdown(u);
      int res = 0, mid = tr[u].l + tr[u].r >> 1;
      if (l <= mid) res = query(u << 1, l, r);
      if (r > mid) res = max(res, query(u << 1 | 1, l, r));
      return res;
    };

    build(1, 1, n);

    int m = ps.size();
    vector<int> res(m);
    for (int i = 0; i < m; i++) {
      int l = ps[i][0], r = ps[i][1], h = r - l + 1;
      l = mp[l], r = mp[r];
      int mx = query(1, l, r);
      modify(1, l, r, mx + h);
      res[i] = query(1, 1, n);
    }
    return res;
  }
};
// @lc code=end
