/*
 * @lc app=leetcode id=2617 lang=cpp
 *
 * [2617] Minimum Number of Visited Cells in a Grid
 */

// @lc code=start
class Solution {
public:
  int minimumVisitedCells(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size();
    if (m == 1 && n == 1) return 1;
    auto id = [&](int x, int y) { return x * n + y; };
    vector<vector<int>> row(m, vector<int>(n + 1)),
        col(n, vector<int>(m + 1));
    for (int i = 0; i < m; i++) iota(row[i].begin(), row[i].end(), 0);
    for (int j = 0; j < n; j++) iota(col[j].begin(), col[j].end(), 0);
    auto find = [&](this auto &&find, auto &p, int x) -> int {
      return x == p[x] ? x : p[x] = find(p, p[x]);
    };

    queue<int> q{{0}};
    row[0][0] = col[0][0] = 1;

    int res = 1;
    while (q.size()) {
      res++;
      for (int _ = q.size(); _--;) {
        int u = q.front(); q.pop();
        int x = u / n, y = u % n;
        for (int ny = find(row[x], y + 1); ny <= min(g[x][y] + y, n - 1);
             ny = find(row[x], ny + 1)) {
          if (x == m - 1 && ny == n - 1) return res;
          q.push(id(x, ny));
          row[x][ny] = ny + 1;
          col[ny][x] = x + 1;
        }
        for (int nx = find(col[y], x + 1); nx <= min(g[x][y] + x, m - 1);
             nx = find(col[y], nx + 1)) {
          if (nx == m - 1 && y == n - 1) return res;
          q.push(id(nx, y));
          col[y][nx] = nx + 1;
          row[nx][y] = y + 1;
        }
      }
    }
    return -1;
  }
};
// @lc code=end
