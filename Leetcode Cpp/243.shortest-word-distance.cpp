/*
 * @lc app=leetcode id=243 lang=cpp
 *
 * [243] Shortest Word Distance
 */

// @lc code=start
class Solution {
 public:
  int shortestDistance(vector<string>& ws, string w1, string w2) {
    int res = 2e9;
    int idx1 = -1, idx2 = -1;
    for (int i = 0; i < ws.size(); i++) {
      if (ws[i] == w1) idx1 = i;
      if (ws[i] == w2) idx2 = i;
      if (~idx1 && ~idx2) res = min(res, abs(idx1 - idx2));
    }
    return res;
  }
};
// @lc code=end
