/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
 public:
  int numSquares(int n) {
    vector<int> f(n + 1, 2e9);
    f[0] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j * j <= i; j++) f[i] = min(f[i], f[i - j * j] + 1);

    return f[n];
  }
};
// @lc code=end
