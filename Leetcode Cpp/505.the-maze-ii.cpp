/*
 * @lc app=leetcode id=505 lang=cpp
 *
 * [505] The Maze II
 */

// @lc code=start
class Solution {
 public:
  using PIII = pair<int, pair<int, int>>;
#define x first
#define y second
  const int INF = 1e9;
  int shortestDistance(vector<vector<int>>& g, vector<int>& start,
                       vector<int>& dest) {
    int m = g.size(), n = g[0].size();
    priority_queue<PIII, vector<PIII>, greater<>> heap;
    int bx = start[0], by = start[1], ex = dest[0], ey = dest[1];
    heap.push({0, {bx, by}});
    vector<vector<int>> dist(m, vector<int>(n, INF));
    dist[bx][by] = 0;
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    auto get_ne = [&](int x, int y) {
      vector<PIII> res;
      static int d[] = {-1, 0, 1, 0, -1};
      for (int i = 0; i < 4; i++) {
        int dx = d[i], dy = d[i + 1];
        int delta;
        for (delta = 1;; delta++) {
          int nx = x + delta * dx, ny = y + delta * dy;
          if (0 <= nx && nx < m && 0 <= ny && ny < n && !g[nx][ny]) continue;
          else break;
        }
        if (delta == 1) continue;
        int nx = x + (delta - 1) * dx, ny = y + (delta - 1) * dy;
        if (vis[nx][ny]) continue;
        res.push_back({delta - 1, {nx, ny}});
      }

      return res;
    };

    while (heap.size()) {
      auto [d, cur] = heap.top(); heap.pop();
      auto [x, y] = cur;
      if (vis[x][y]) continue;
      if (x == ex && y == ey) return d;
      vis[x][y] = true;
      dist[x][y] = d;

      for (auto [dis, ne] : get_ne(x, y)) {
        auto [nx, ny] = ne;
        if (d + dis < dist[nx][ny]) {
          dist[nx][ny] = d + dis;
          heap.push({dist[nx][ny], {nx, ny}});
        }
      }
    }

    return -1;
  }
};
// @lc code=end
