/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size();
    for (int i = 1; i < m; i++)
      for (int j = 0; j < n; j++) {
        int t = INT_MAX;
        for (int k = max(0, j - 1); k <= min(n - 1, j + 1); k++)
          t = min(t, A[i - 1][k] + A[i][j]);
        A[i][j] = t;
      }
    
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
      res = min(res, A[m - 1][i]);
    return res;
  }
};
// @lc code=end
