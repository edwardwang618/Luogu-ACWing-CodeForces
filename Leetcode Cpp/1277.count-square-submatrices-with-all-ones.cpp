/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
class Solution {
 public:
  int countSquares(vector<vector<int>>& m) {
    int res = 0;
    for (int i = 0; i < m.size(); i++)
      for (int j = 0; j < m[0].size(); j++)
        if (m[i][j]) {
          if (i && j)
            m[i][j] = min({m[i - 1][j], m[i][j - 1], m[i - 1][j - 1]}) + 1;
          else
            m[i][j] = 1;

          res += m[i][j];
        }
    return res;
  }
};
// @lc code=end
