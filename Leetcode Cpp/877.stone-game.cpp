/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */

// @lc code=start
class Solution {
 public:
  // bool stoneGame(vector<int>& a) {
  //   int n = a.size(), f[n][n];
  //   memset(f, 0, sizeof f);
  //   for (int len = 1; len <= n; len++)
  //     for (int l = 0; l + len - 1 < n; l++) {
  //       int r = l + len - 1;
  //       if (len == 1) f[l][r] = a[l];
  //       else f[l][r] = max(a[l] - f[l + 1][r], a[r] - f[l][r - 1]);
  //     }

  //   return f[0][n - 1] > 0;
  // }

  bool stoneGame(vector<int>& a) {
    return true;
  }
};
// @lc code=end
