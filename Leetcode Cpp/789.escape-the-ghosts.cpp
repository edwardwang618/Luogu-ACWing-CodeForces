/*
 * @lc app=leetcode id=789 lang=cpp
 *
 * [789] Escape The Ghosts
 */

// @lc code=start
class Solution {
public:
  bool escapeGhosts(vector<vector<int>> &gs, vector<int> &t) {
    int d0 = abs(t[0]) + abs(t[1]);
    for (auto &g : gs) {
      int di = abs(g[0] - t[0]) + abs(g[1] - t[1]);
      if (di <= d0) return false;
    }
    return true;
  }
};
// @lc code=end
