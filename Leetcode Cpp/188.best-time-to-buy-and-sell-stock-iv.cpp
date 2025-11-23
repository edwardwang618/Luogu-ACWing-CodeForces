/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(int k, vector<int>& ps) {
    int n = ps.size();
    int res = 0;
    if (k >= n / 2) {
      for (int i = 1; i < n; i++) res += max(ps[i] - ps[i - 1], 0);
      return res;
    }

    int buy[n][k + 1], sell[n][k + 1];
    for (int i = 1; i <= k; i++) buy[0][i] = -ps[0];
    buy[0][0] = -2e9;
    memset(sell, 0, sizeof sell);
    for (int i = 1; i < n; i++)
      for (int j = 0; j <= k; j++) {
        buy[i][j] = buy[i - 1][j];
        if (j) buy[i][j] = max(buy[i][j], sell[i - 1][j - 1] - ps[i]);
        sell[i][j] = max(sell[i - 1][j], buy[i - 1][j] + ps[i]);
      }

    return sell[n - 1][k];
  }
};
// @lc code=end
