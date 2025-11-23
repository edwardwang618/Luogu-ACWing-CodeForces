/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& ps, int fee) {
    // int n = ps.size();
    // int f[n + 1][2];
    // memset(f, -0x3f, sizeof f);
    // f[0][0] = 0;
    // for (int i = 1; i <= n; i++) {
    //   f[i][0] = max(f[i - 1][0], f[i - 1][1] + ps[i - 1] - fee);
    //   f[i][1] = max(f[i - 1][1], f[i - 1][0] - ps[i - 1]);
    // }
    // return f[n][0];
    int n = ps.size();
    int f[n][2];
    memset(f, -0x3f, sizeof f);
    f[0][0] = f[0][1] = 0;
    for (int i = 1; i < n; i++) {
      f[i][0] = max(f[i - 1][0], f[i - 1][1] + ps[i] - ps[i - 1] - fee);
      f[i][1] = max(f[i - 1][1] + ps[i] - ps[i - 1], f[i - 1][0]);
    }

    return max(f[n - 1][0], f[n - 1][1] - fee);
  }
};
// @lc code=end
