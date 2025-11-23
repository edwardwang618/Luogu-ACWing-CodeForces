/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
class Solution {
 public:

  vector<int> p;

  int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
  }

  vector<int> findRedundantConnection(vector<vector<int>>& es) {
    int n = 0;
    for (auto &e : es) n = max({n, e[0], e[1]});
    p.resize(n + 1);
    for (int i = 1; i <= n; i++) p[i] = i;
    for (auto &e : es) {
      int x = e[0], y = e[1], px = find(x), py = find(y);
      if (px != py) p[px] = py;
      else return e;
    }

    return {};
  }
};
// @lc code=end
