/*
 * @lc app=leetcode id=2257 lang=cpp
 *
 * [2257] Count Unguarded Cells in the Grid
 */

// @lc code=start
class Solution {
 public:
  int countUnguarded(int m, int n, vector<vector<int>>& guards,
                     vector<vector<int>>& walls) {
    vector<vector<int>> g(m, vector<int>(n));
    for (auto& v : walls) g[v[0]][v[1]] = 1;
    for (auto& v : guards) g[v[0]][v[1]] = 2;
    for (auto& v : guards) {
      int x = v[0], y = v[1];
      static int d[] = {-1, 0, 1, 0, -1};
      for (int k = 0; k < 4; k++) {
        int dx = d[k], dy = d[k + 1];
        for (int s = 1;; s++) {
          int nx = x + s * dx, ny = y + s * dy;
          if (0 <= nx && nx < m && 0 <= ny && ny < n) {
            if (g[nx][ny] == 1 || g[nx][ny] == 2) break;
            g[nx][ny] = 3;
          } else
            break;
        }
      }
    }

    int res = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (!g[i][j]) res++;
    return res;
  }
};
// @lc code=end
