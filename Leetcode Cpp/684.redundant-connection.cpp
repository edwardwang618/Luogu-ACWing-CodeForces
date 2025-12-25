/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &es) {
    int n = es.size();
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    for (auto &e : es) {
      int x = e[0], y = e[1], px = find(x), py = find(y);
      if (px != py)
        p[px] = py;
      else
        return e;
    }

    return {};
  }
};
// @lc code=end
