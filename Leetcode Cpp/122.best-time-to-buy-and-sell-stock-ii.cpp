/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& ps) {
    int res = 0;
    for (int i = 1; i < ps.size(); i++) res += max(0, ps[i] - ps[i - 1]);
    return res;
  }
};
// @lc code=end
