/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 */

// @lc code=start
class Solution {
 public:
  using PII = pair<int, int>;
  int d[5] = {-1, 0, 1, 0, -1};
  int shortestBridge(vector<vector<int>>& grid) {
    queue<PII> q;
    for (int i = 0; i < grid.size(); i++)
      for (int j = 0; j < grid[0].size(); j++)
        if (grid[i][j] == 1) {
          dfs(i, j, q, grid);
          return bfs(q, grid);
        }
    return 0;
  }

  int bfs(queue<PII>& q, vector<vector<int>>& g) {
    int res = 0;
    while (q.size()) {
      res++;
      for (int k = q.size(); k; k--) {
        auto t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        for (int i = 0; i < 4; i++) {
          int nx = t.first + d[i], ny = t.second + d[i + 1];
          if (0 <= nx && nx < g.size() && 0 <= ny && ny < g[0].size()) {
            if (g[nx][ny] == 1) return res - 1;
            if (g[nx][ny] == -1) continue;
            g[nx][ny] = -1;
            q.push({nx, ny});
          }
        }
      }
    }

    return 0;
  }

  void dfs(int i, int j, queue<PII>& q, vector<vector<int>>& g) {
    q.push({i, j});
    g[i][j] = -1;
    for (int k = 0; k < 4; k++) {
      int ni = i + d[k], nj = j + d[k + 1];
      if (0 <= ni && ni < g.size() && 0 <= nj && nj < g[0].size() && g[ni][nj] == 1)
        dfs(ni, nj, q, g);
    }
  }
};
// @lc code=end
