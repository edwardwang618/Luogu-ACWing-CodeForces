/*
 * @lc app=leetcode id=1861 lang=cpp
 *
 * [1861] Rotating the Box
 */

// @lc code=start
class Solution {
 public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& g) {
    int m = g.size(), n = g[0].size();
    vector<vector<char>> res(n, vector<char>(m, '.'));
    for (int i = 0; i < m; i++)
      for (int j = n - 1, idx = j; j >= 0; j--) {
        if (g[i][j] == '*') {
          res[j][m - 1 - i] = '*';
          idx = j - 1;
        } else if (g[i][j] == '#') res[idx--][m - 1 - i] = '#';
      }

    return res;
  }
};
// @lc code=end
