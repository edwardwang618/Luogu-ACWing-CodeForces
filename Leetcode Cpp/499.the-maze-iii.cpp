/*
 * @lc app=leetcode id=499 lang=cpp
 *
 * [499] The Maze III
 */

// @lc code=start
class Solution {
 public:
  struct Node {
    int x, y;
    int dist;
    string path;
  };

  string findShortestWay(vector<vector<int>> &g, vector<int> &beg,
                         vector<int> &end) {
    int m = g.size(), n = g[0].size();
    int ex = end[0], ey = end[1];
    static auto cmp = [](const Node &n1, const Node &n2) {
      return n1.dist != n2.dist ? n1.dist > n2.dist : n1.path > n2.path;
    };
    static vector<int> d[4] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    static char dch[] = "dlru";
    vector<vector<bool>> vis(m, vector<bool>(n));
    priority_queue<Node, vector<Node>, decltype(cmp)> heap(cmp);
    heap.push({beg[0], beg[1], 0, ""});
    int dist[m][n];
    memset(dist, 0x3f, sizeof dist);
    while (heap.size()) {
      auto t = heap.top();
      heap.pop();
      int x = t.x, y = t.y, dis = t.dist;
      if (vis[x][y]) continue;
      if (x == ex && y == ey) return t.path;

      vis[x][y] = true;
      dist[x][y] = dis;
      for (int k = 0; k < 4; k++) {
        int dx = d[k][0], dy = d[k][1];
        x = t.x, y = t.y;
        int step = 0;
        while (0 <= x + dx && x + dx < m && 0 <= y + dy && y + dy < n &&
               g[x + dx][y + dy] != 1) {
          x += dx, y += dy;
          step++;
          if (x == ex && y == ey) break;
        }
        if (!vis[x][y] && dist[x][y] >= dis + step) {
          dist[x][y] = dis + step;
          heap.push({x, y, dist[x][y], t.path + dch[k]});
        }
      }
    }

    return "impossible";
  }
};
// @lc code=end
