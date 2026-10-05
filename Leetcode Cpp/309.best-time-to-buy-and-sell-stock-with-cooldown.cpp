/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
  // int maxProfit(vector<int> &ps) {
  //   int n = ps.size();
  //   vector<int> hold(n), cool(n), sold(n);
  //   hold[0] = -ps[0];
  //   for (int i = 1; i < n; i++) {
  //     hold[i] = max(hold[i - 1], cool[i - 1] - ps[i]);
  //     cool[i] = max(cool[i - 1], sold[i - 1]);
  //     sold[i] = hold[i - 1] + ps[i];
  //   }
  //   return max(cool[n - 1], sold[n - 1]);
  // }

  int maxProfit(vector<int> &ps) {
    int n = ps.size();
    vector<int> hold(n), cool(n), sold(n);
    for (int i = 1; i < n; i++) {
      hold[i] = max(hold[i - 1] + ps[i] - ps[i - 1], cool[i - 1]);
      cool[i] = max(cool[i - 1], sold[i - 1]);
      sold[i] = hold[i - 1] + ps[i] - ps[i - 1];
    }
    return max({sold[n - 1], cool[n - 1]});
  }
};
// @lc code=end
