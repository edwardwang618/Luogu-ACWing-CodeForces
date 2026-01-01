/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {
 public:
  using PII = pair<int, int>;
  int shortestPathBinaryMatrix(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size();
    int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
    int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
    if (g[0][0]) return -1;
    if (m == 1 && n == 1) return 1;
    int res = 1;
    queue<PII> q;
    q.emplace(0, 0);
    g[0][0] = -1;
    while (q.size()) {
      res++;
      for (int i = q.size(); i; i--) {
        auto t = q.front();
        q.pop();
        for (int j = 0; j < 8; j++) {
          int nx = t.first + dx[j], ny = t.second + dy[j];
          if (0 <= nx && nx < m && 0 <= ny && ny < n && !g[nx][ny]) {
            if (nx == m - 1 && ny == n - 1) return res;
            g[nx][ny] = -1;
            q.emplace(nx, ny);
          }
        }
      }
    }

    return -1;
  }
};
// @lc code=end
