/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
  int maxSubArray(vector<int> &a) {
    int s = 0, res = -2e9;
    for (int x : a) {
      s = max(x, s + x);
      res = max(res, s);
    }
    return res;
  }
};
// @lc code=end
