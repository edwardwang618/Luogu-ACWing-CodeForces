/*
 * @lc app=leetcode id=2371 lang=cpp
 *
 * [2371] Minimize Maximum Value in a Grid
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> minScore(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size();
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        v.push_back({g[i][j], i, j});

    sort(v.begin(), v.end());

    vector<int> rowMax(m, 0), colMax(n, 0);
    vector<vector<int>> res(m, vector<int>(n));
    for (auto &[_, i, j] : v) {
      int x = max(rowMax[i], colMax[j]) + 1;
      res[i][j] = rowMax[i] = colMax[j] = x;
    }

    return res;
  }
};
// @lc code=end
