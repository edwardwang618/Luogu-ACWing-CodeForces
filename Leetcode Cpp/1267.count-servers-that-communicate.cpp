/*
 * @lc app=leetcode id=1267 lang=cpp
 *
 * [1267] Count Servers that Communicate
 */

// @lc code=start
class Solution {
 public:
  int countServers(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size();
    vector<int> row(m, 0), col(n, 0);
    int res = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j] == 1) {
          res++;
          row[i]++;
          col[j]++;
        }

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j] == 1 && row[i] == 1 && col[j] == 1) res--;
    return res;
  }
};
// @lc code=end
