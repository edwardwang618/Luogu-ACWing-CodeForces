/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 */

// @lc code=start
class Solution {
 public:
  struct Node {
    int x, y, k;
  };

  int shortestPath(vector<vector<int>>& g, int k) {
    int m = g.size(), n = g[0].size();
    if (m == 1 && n == 1) return 0;
    int d[] = {1, 0, -1, 0, 1};
    bool vis[m][n][k + 1];
    memset(vis, 0, sizeof vis);
    queue<Node> q;
    q.emplace(0, 0, k);
    vis[0][0][k] = true;
    int step = 0;
    while (q.size()) {
      step++;
      for (int i = q.size(); i; i--) {
        auto [x, y, k] = q.front(); q.pop();
        for (int j = 0; j < 4; j++) {
          int nx = x + d[j], ny = y + d[j + 1];
          if (0 <= nx && nx < m && 0 <= ny && ny < n) {
            if (!g[nx][ny] && !vis[nx][ny][k]) {
              if (nx == m - 1 && ny == n - 1) return step;
              q.emplace(nx, ny, k);
              vis[nx][ny][k] = true;
            }
            if (g[nx][ny] && k && !vis[nx][ny][k - 1]) {
              if (nx == m - 1 && ny == n - 1) return step;
              q.emplace(nx, ny, k - 1);
              vis[nx][ny][k - 1] = true;
            }
          }
        }
      }
    }

    return -1;
  }
};
// @lc code=end
