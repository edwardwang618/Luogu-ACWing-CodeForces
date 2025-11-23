/*
 * @lc app=leetcode id=850 lang=cpp
 *
 * [850] Rectangle Area II
 */

// @lc code=start
class Solution {
 public:
  struct Seg {
    int l, r, x, w;
    bool operator<(const Seg &seg) const { return x < seg.x; }
  };

  struct Node {
    int l, r;
    int cnt, len;
  };

  vector<Node> tr;
  vector<int> ys;

  void pushup(int u) {
    if (tr[u].cnt)
      tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
    else {
      if (tr[u].l != tr[u].r)
        tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
      else
        tr[u].len = 0;
    }
  }

  void build(int u, int l, int r) {
    tr[u] = {l, r, 0, 0};
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  }

  void modify(int u, int l, int r, int w) {
    if (l <= tr[u].l && tr[u].r <= r) {
      tr[u].cnt += w;
    } else {
      int mid = tr[u].l + tr[u].r >> 1;
      if (l <= mid) modify(u << 1, l, r, w);
      if (r > mid) modify(u << 1 | 1, l, r, w);
    }
    pushup(u);
  }

  int rectangleArea(vector<vector<int>> &rectangles) {
    vector<Seg> v;
    for (auto &rect : rectangles) {
      v.push_back({rect[1], rect[3], rect[0], 1});
      v.push_back({rect[1], rect[3], rect[2], -1});
      ys.push_back(rect[1]);
      ys.push_back(rect[3]);
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int n = ys.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) mp[ys[i]] = i;
    tr.resize(n - 1 << 2);
    build(1, 0, n - 2);

    sort(v.begin(), v.end());
    int MOD = 1e9 + 7;
    int res = 0;
    for (int i = 0, j; i < v.size(); i++) {
      if (i) res = (res + (long)tr[1].len * (v[i].x - v[i - 1].x)) % MOD;
      j = i;
      while (j < v.size() && v[i].x == v[j].x) {
        modify(1, mp[v[j].l], mp[v[j].r] - 1, v[j].w);
        j++;
      }
      i = j - 1;
    }

    return res;
  }
};
// @lc code=end
