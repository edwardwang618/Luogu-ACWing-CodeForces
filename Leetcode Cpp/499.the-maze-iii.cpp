/*
 * @lc app=leetcode id=499 lang=cpp
 *
 * [499] The Maze III
 */

// @lc code=start
class Solution {
public:
  struct Node {
    int u, dist;
    string path;
  };
  string findShortestWay(vector<vector<int>> &g, vector<int> &beg,
                         vector<int> &end) {
    int m = g.size(), n = g[0].size();
    auto in_bound = [&](int x, int y) {
      return 0 <= x && x < m && 0 <= y && y < n;
    };
    auto id = [&](int x, int y) { return x * n + y; };
    int st = id(beg[0], beg[1]), ed = id(end[0], end[1]);
    auto cmp = [](auto &a, auto &b) {
      if (a.dist != b.dist)
        return a.dist > b.dist;
      return a.path > b.path;
    };
    static int dx[4] = {1, 0, 0, -1};
    static int dy[4] = {0, -1, 1, 0};
    static char dch[] = "dlru";
    vector<int> dist(m * n, 2e9);
    vector<string> best_path(m * n);
    priority_queue<Node, vector<Node>, decltype(cmp)> heap(cmp);
    dist[st] = 0;
    heap.emplace(st, 0, "");
    while (heap.size()) {
      auto [u, dis, path] = heap.top(); heap.pop();
      if (dis > dist[u] || path != best_path[u]) continue;
      if (u == ed) return path;
      int x = u / n, y = u % n;
      for (int k = 0; k < 4; k++) {
        int nx = x, ny = y, step = 0;
        while (in_bound(nx + dx[k], ny + dy[k]) &&
               g[nx + dx[k]][ny + dy[k]] == 0) {
          nx += dx[k], ny += dy[k];
          step++;
          if (id(nx, ny) == ed) break;
        }
        int nid = id(nx, ny), nd = dis + step;
        string np = path + dch[k];
        if (dist[nid] > nd || (dist[nid] == nd && np < best_path[nid])) {
          dist[nid] = nd;
          best_path[nid] = np;
          heap.emplace(nid, nd, np);
        }
      }
    }
    return "impossible";
  }
};
// @lc code=end
