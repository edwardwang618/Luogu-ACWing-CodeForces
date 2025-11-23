/*
 * @lc app=leetcode id=286 lang=cpp
 *
 * [286] Walls and Gates
 */

// @lc code=start
class Solution {
 public:
  using PII = pair<int, int>;
  void wallsAndGates(vector<vector<int>>& g) {
    const int INF = (1 << 31) - 1;
    int m = g.size(), n = g[0].size();
    queue<PII> q;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (!g[i][j]) q.push({i, j});
    
    while (q.size()) {
      for (int i = q.size(); i; i--) {
        auto t = q.front(); q.pop();
        int x = t.first, y = t.second;
        static int d[] = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
          int nx = x + d[k], ny = y + d[k + 1];
          if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny] == INF) {
            g[nx][ny] = g[x][y] + 1;
            q.push({nx, ny});
          }
        }
      }
    }
  }
};
// @lc code=end
