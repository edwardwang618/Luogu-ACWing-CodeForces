/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution {
 public:
  int findLength(vector<int>& a, vector<int>& b) {
    int res = 0, m = a.size(), n = b.size();
    int f[m + 1][n + 1];
    memset(f, 0, sizeof f);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (a[i] == b[j]) {
          f[i + 1][j + 1] = f[i][j] + 1;
          res = max(res, f[i + 1][j + 1]);
        }
    return res;
  }
};
// @lc code=end
