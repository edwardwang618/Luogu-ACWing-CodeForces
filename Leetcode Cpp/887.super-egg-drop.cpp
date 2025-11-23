/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 */

// @lc code=start
class Solution {
 public:
  int superEggDrop(int k, int n) {
    int f[n + 1][k + 1];
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) f[i][j] = f[i - 1][j - 1] + 1 + f[i - 1][j];
      if (f[i][k] >= n) return i;
    }

    return -1;
  }
};
// @lc code=end
