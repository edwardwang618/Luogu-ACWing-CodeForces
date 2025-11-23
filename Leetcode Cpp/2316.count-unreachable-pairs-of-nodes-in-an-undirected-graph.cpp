/*
 * @lc app=leetcode id=2316 lang=cpp
 *
 * [2316] Count Unreachable Pairs of Nodes in an Undirected Graph
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  ll countPairs(int n, vector<vector<int>>& es) {
    vector<int> p(n), sz(n, 1);
    for (int i = 0; i < n; i++) p[i] = i;
    function<int(int)> find = [&](int x) {
      if (x != p[x]) p[x] = find(p[x]);
      return p[x];
    };

    for (auto& e : es) {
      int px = find(e[0]), py = find(e[1]);
      if (px != py) {
        p[px] = py;
        sz[py] += sz[px];
      }
    }

    ll res = 0;
    for (int i = 0; i < n; i++)
      if (i == p[i]) res += (ll)sz[i] * (n - sz[i]);

    return res / 2;
  }
};
// @lc code=end
