/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
 public:
  void setZeroes(vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size();
    bool row0 = false, col0 = false;
    for (int i = 0; i < n; i++)
      if (!A[0][i]) {
        row0 = true;
        break;
      }
    for (int i = 0; i < m; i++)
      if (!A[i][0]) {
        col0 = true;
        break;
      }

    for (int i = 1; i < m; i++)
      for (int j = 1; j < n; j++)
        if (!A[i][j]) A[i][0] = A[0][j] = 0;

    for (int i = 1; i < m; i++)
      if (!A[i][0]) fill(A[i].begin() + 1, A[i].end(), 0);
    for (int j = 1; j < n; j++)
      if (!A[0][j])
        for (int k = 1; k < m; k++) A[k][j] = 0;

    if (row0) fill(A[0].begin(), A[0].end(), 0);
    if (col0) for (int i = 0; i < m; i++) A[i][0] = 0;
  }
};
// @lc code=end
