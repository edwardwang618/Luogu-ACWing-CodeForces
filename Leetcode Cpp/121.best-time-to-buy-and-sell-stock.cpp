/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& ps) {
    int res = 0, min_p = 2e9;
    for (int x : ps) {
      res = max(res, max(x - min_p, 0));
      min_p = min(min_p, x);
    }
    return res;
  }
};
// @lc code=end
