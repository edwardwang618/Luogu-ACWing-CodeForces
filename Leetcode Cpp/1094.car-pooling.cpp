/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int diff[1001] = {0};
    for (auto& trip : trips) diff[trip[1]] += trip[0], diff[trip[2]] -= trip[0];
    int sum = 0;
    for (int x : diff) {
      sum += x;
      if (sum > capacity) return false;
    }
    return true;
  }
};
// @lc code=end
