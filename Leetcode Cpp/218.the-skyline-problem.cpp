/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class Solution {
 public:
  struct Node {
    int l, r, h;
  };

  vector<Node> tr;

  void pushdown(int u) {
    auto &t = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
    if (t.h) {
      l.h = r.h = t.h;
      t.h = 0;
    }
  }

  void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  }

  void update(int u, int l, int r, int h) {
    if (l <= tr[u].l && tr[u].r <= r) {
      tr[u].h = max(tr[u].h, h);
      return;
    }

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) update(u << 1, l, r, h);
    if (r > mid) update(u << 1 | 1, l, r, h);
  }

  vector<vector<int>> getSkyline(vector<vector<int>> &bs) {
    sort(bs.begin(), bs.end(),
         [&](const vector<int> &v1, const vector<int> &v2) {
           return v1[2] < v2[2];
         });

    vector<int> v;
    for (auto &b : bs) {
      v.push_back(b[0]);
      v.push_back(b[1]);
    }

    sort(v.begin(), v.end());
    int n = v.erase(unique(v.begin(), v.end()), v.end()) - v.begin();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) mp[v[i]] = i;
    tr.resize(n << 2);
    build(1, 0, n);
    for (auto &b : bs) update(1, mp[b[0]], mp[b[1]] - 1, b[2]);

    vector<vector<int>> res;
    int last = 0;
    dfs(1, last, v, res);
    return res;
  }

  void dfs(int u, int &last, vector<int> &v, vector<vector<int>> &res) {
    if (tr[u].l == tr[u].r || tr[u].h) {
      if (tr[u].h != last) {
        res.push_back({v[tr[u].l], tr[u].h});
        last = tr[u].h;
      }
      return;
    }
    dfs(u << 1, last, v, res);
    dfs(u << 1 | 1, last, v, res);
  }
};
// @lc code=end
