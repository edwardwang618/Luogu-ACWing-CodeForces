/*
 * @lc app=leetcode id=505 lang=cpp
 *
 * [505] The Maze II
 */

// @lc code=start
class Solution {
public:
  int shortestDistance(vector<vector<int>> &g, vector<int> &start,
                       vector<int> &dest) {
    int m = g.size(), n = g[0].size();
    auto in_bound = [&](int x, int y) {
      return 0 <= x && x < m && 0 <= y && y < n;
    };
    auto id = [&](int x, int y) {
      return x * n + y;
    };
    int st = id(start[0], start[1]), ed = id(dest[0], dest[1]);
    vector<int> dist(m * n, 2e9);
    dist[st] = 0;
    using PII = pair<int, int>;
    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.emplace(0, st);
    while (heap.size()) {
      auto [dis, u] = heap.top(); heap.pop();
      if (u == ed) return dis;
      if (dis > dist[u]) continue;
      static int d[] = {1, 0, -1, 0, 1};
      int x = u / n, y = u % n;
      for (int k = 0; k < 4; k++) {
        int nx = x, ny = y, dx = d[k], dy = d[k + 1];
        int delta = 0;
        while (in_bound(nx + dx, ny + dy) && !g[nx + dx][ny + dy]) {
          delta++;
          nx += dx, ny += dy;
        }
        int nid = id(nx, ny);
        if (dist[nid] > dis + delta) {
          dist[nid] = dis + delta;
          heap.emplace(dist[nid], nid);
        }
      }
    }

    return -1;
  }
};
// @lc code=end
