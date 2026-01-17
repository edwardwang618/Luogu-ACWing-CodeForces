/*
 * @lc app=leetcode id=2492 lang=cpp
 *
 * [2492] Minimum Score of a Path Between Two Cities
 */

// @lc code=start
class Solution {
public:
  int minScore(int n, vector<vector<int>> &es) {
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    for (auto &e : es) p[find(e[0])] = find(e[1]);

    int res = 2e9;
    int f1 = find(1);
    for (auto &e : es)
      if (find(e[0]) == f1) res = min(res, e[2]);
    return res;
  }
};
// @lc code=end
