/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 */

// @lc code=start
class Solution {
 public:
  int matrixScore(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size();
    for (int i = 0; i < m; i++)
      if (!g[i][0])
        for (int j = 0; j < n; j++) g[i][j] ^= 1;

    for (int j = 1; j < n; j++) {
      int cnt = 0;
      for (int i = 0; i < m; i++)
        if (!g[i][j]) cnt++;
      if (cnt > m - cnt)
        for (int i = 0; i < m; i++) g[i][j] ^= 1;
    }

    int res = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j]) res += 1 << n - 1 - j;
    return res;
  }
};
// @lc code=end
