/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 */

// @lc code=start
class Solution {
 public:
  int removeCoveredIntervals(vector<vector<int>>& a) {
    int res = 0, r = -1;
    sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y) {
      return x[0] != y[0] ? x[0] < y[0] : x[1] > y[1];
    });

    for (auto& p : a) {
      if (p[1] <= r) continue;
      res++;
      r = p[1];
    }

    return res;
  }
};
// @lc code=end
