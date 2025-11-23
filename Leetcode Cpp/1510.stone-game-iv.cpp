/*
 * @lc app=leetcode id=1510 lang=cpp
 *
 * [1510] Stone Game IV
 */

// @lc code=start
class Solution {
 public:
  bool winnerSquareGame(int n) {
    vector<bool> f(n + 1);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= i / j; j++)
        if (!f[i - j * j]) {
          f[i] = true;
          break;
        }
    return f[n];
  }
};
// @lc code=end
