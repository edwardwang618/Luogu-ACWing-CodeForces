/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int>& a) {
    int res = -2e9, cur_sum = 0;
    for (int x : a) {
      cur_sum = max(x, cur_sum + x);
      res = max(res, cur_sum);
    }
    return res;
  }
};
// @lc code=end
