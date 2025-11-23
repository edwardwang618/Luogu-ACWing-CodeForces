/*
 * @lc app=leetcode id=1266 lang=cpp
 *
 * [1266] Minimum Time Visiting All Points
 */

// @lc code=start
class Solution {
 public:
  int minTimeToVisitAllPoints(vector<vector<int>>& ps) {
    int res = 0;
    auto f = [](const vector<int>& p1, const vector<int>& p2) {
      return max(abs(p1[0] - p2[0]), abs(p1[1] - p2[1]));
    };
    for (int i = 0; i < ps.size() - 1; i++) res += f(ps[i], ps[i + 1]);
    return res;
  }
};
// @lc code=end
