/*
 * @lc app=leetcode id=490 lang=cpp
 *
 * [490] The Maze
 */

// @lc code=start
class Solution {
public:
  bool hasPath(vector<vector<int>> &g, vector<int> &start, vector<int> &end) {
    int m = g.size(), n = g[0].size();
    auto id = [&](int x, int y) { return x * n + y; };
    int st = id(start[0], start[1]), ed = id(end[0], end[1]);
    queue<int> q;
    q.emplace(st);
    vector<bool> vis(m * n);
    vis[st] = true;
    while (q.size()) {
      int cur = q.front();
      q.pop();
      int x = cur / n, y = cur % n;
      static int d[] = {1, 0, -1, 0, 1};
      for (int k = 0; k < 4; k++) {
        int dx = d[k], dy = d[k + 1];
        int nx = x, ny = y;
        while (0 <= nx + dx && nx + dx < m && 0 <= ny + dy && ny + dy < n &&
               !g[nx + dx][ny + dy])
          nx += dx, ny += dy;
        int nid = id(nx, ny);
        if (nid == ed)
          return true;
        if (!vis[nid]) {
          vis[nid] = true;
          q.push(nid);
        }
      }
    }
    return false;
  }
};
// @lc code=end
