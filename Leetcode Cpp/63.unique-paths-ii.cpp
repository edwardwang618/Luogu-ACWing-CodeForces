/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size();
    // f[i][j] 如果(i,j)是障碍物，f[i][j]=0
    int f[m][n];
    memset(f, 0, sizeof f);

    if (A[0][0]) return 0;

    f[0][0] = 1;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (A[i][j]) {
          f[i][j] = 0;
          continue;
        }

        if (i) f[i][j] += f[i - 1][j];
        if (j) f[i][j] += f[i][j - 1];
      }

    return f[m - 1][n - 1];
  }
};
// @lc code=end
