/*
 * @lc app=leetcode id=311 lang=cpp
 *
 * [311] Sparse Matrix Multiplication
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
    vector c(a.size(), vector(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++)
      for (int j = 0; j < a[0].size(); j++)
        if (a[i][j])
          for (int k = 0; k < b[0].size(); k++) c[i][k] += a[i][j] * b[j][k];
    return c;
  }
};
// @lc code=end
