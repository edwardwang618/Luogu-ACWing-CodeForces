/*
 * @lc app=leetcode id=883 lang=cpp
 *
 * [883] Projection Area of 3D Shapes
 */

// @lc code=start
class Solution {
public:
  int projectionArea(vector<vector<int>> &g) {
    int n = g.size(), res = 0;
    for (int i = 0; i < n; i++) {
      int r = 0, c = 0;
      for (int j = 0; j < n; j++) {
        if (g[i][j]) res++;
        r = max(r, g[i][j]);
        c = max(c, g[j][i]);
      }
      res += r + c;
    }
    return res;
  }
};
// @lc code=end
