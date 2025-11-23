/*
 * @lc app=leetcode id=1335 lang=cpp
 *
 * [1335] Minimum Difficulty of a Job Schedule
 */

// @lc code=start
class Solution {
 public:
  int minDifficulty(vector<int>& a, int d) {
    int n = a.size();
    if (n < d) return -1;
    int f[d + 1][n];
    memset(f, 0x3f, sizeof f);
    for (int i = n - 1, cur_max = 0; i >= 0; i--) {
      cur_max = max(cur_max, a[i]);
      f[1][i] = cur_max;
    }

    for (int i = 2; i <= d; i++)
      for (int j = 0; j <= n - i; j++) {
        int cur_max = 0;
        for (int k = j; k <= n - i; k++) {
          cur_max = max(cur_max, a[k]);
          f[i][j] = min(f[i][j], cur_max + f[i - 1][k + 1]);
        }
      }

    return f[d][0];
  }
};
// @lc code=end
