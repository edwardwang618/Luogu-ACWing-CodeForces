/*
 * @lc app=leetcode id=1992 lang=cpp
 *
 * [1992] Find All Groups of Farmland
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> findFarmland(vector<vector<int>> &g) {
    vector<vector<int>> res;
    int m = g.size(), n = g[0].size();
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j]) {
          int r1 = i, c1 = j;
          int r2 = i, c2 = j;
          while (r2 + 1 < m && g[r2 + 1][j]) r2++;
          while (c2 + 1 < n && g[i][c2 + 1]) c2++;
          res.push_back({r1, c1, r2, c2});

          for (int x = r1; x <= r2; x++)
            for (int y = c1; y <= c2; y++) g[x][y] = 0;
        }
    return res;
  }
};
// @lc code=end
