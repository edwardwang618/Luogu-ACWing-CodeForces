/*
 * @lc app=leetcode id=1368 lang=cpp
 *
 * [1368] Minimum Cost to Make at Least One Valid Path in a Grid
 */

// @lc code=start
class Solution {
 public:
  struct Node {
    int x, y, dist;
  };

  int minCost(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size();
    deque<Node> dq;
    dq.push_back({0, 0, 0});
    bool vis[m][n];
    memset(vis, 0, sizeof vis);
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (dq.size()) {
      auto t = dq.front();
      dq.pop_front();
      int x = t.x, y = t.y, dist = t.dist;
      if (x == m - 1 && y == n - 1) return dist;
      vis[x][y] = true;
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && !vis[nx][ny]) {
          if (g[x][y] == i + 1)
            dq.push_front({nx, ny, dist});
          else
            dq.push_back({nx, ny, dist + 1});
        }
      }
    }

    return -1;
  }
};
// @lc code=end
