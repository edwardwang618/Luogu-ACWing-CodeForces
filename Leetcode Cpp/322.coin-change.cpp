/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int f[n + 1][amount + 1];
    fill(&f[0][0], &f[0][0] + (n + 1) * (amount + 1), amount + 1);
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= amount; j++) {
        f[i][j] = f[i - 1][j];
        if (j >= coins[i - 1])
          f[i][j] = min(f[i][j], f[i][j - coins[i - 1]] + 1);
      }

    return f[n][amount] == amount + 1 ? -1 : f[n][amount];
  }
};
// @lc code=end
