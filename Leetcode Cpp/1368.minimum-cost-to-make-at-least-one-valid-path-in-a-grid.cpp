/*
 * @lc app=leetcode id=1368 lang=cpp
 *
 * [1368] Minimum Cost to Make at Least One Valid Path in a Grid
 */

// @lc code=start
class Solution {
 public:
  using PII = pair<int, int>;
  int minCost(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size();
    deque<PII> dq;
    dq.emplace_back(0, 0);
    constexpr int INF = 2e9;
    vector<vector<int>> dist(m, vector<int>(n, INF));
    dist[0][0] = 0;
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    static int dx[] = {0, 0, 1, -1};
    static int dy[] = {1, -1, 0, 0};
    while (dq.size()) {
      auto [x, y] = dq.front(); dq.pop_front();
      if (vis[x][y]) continue;
      if (x == m - 1 && y == n - 1) return dist[x][y];
      vis[x][y] = true;
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < m && 0 <= ny && ny < n) {
          int w = g[x][y] == i + 1 ? 0 : 1;
          if (dist[nx][ny] > dist[x][y] + w) {
            dist[nx][ny] = dist[x][y] + w;
            if (!w) dq.emplace_front(nx, ny);
            else dq.emplace_back(nx, ny);
          }
        }
      }
    }

    return -1;
  }
};
// @lc code=end
