/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& ps) {
    int res = 0;
    for (int i = 0, min_p = 2e9; i < ps.size(); i++) {
      res = max(res, max(ps[i] - min_p, 0));
      min_p = min(min_p, ps[i]);
    }
    return res;
  }
};
// @lc code=end
