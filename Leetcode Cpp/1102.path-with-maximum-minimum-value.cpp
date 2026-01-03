/*
 * @lc app=leetcode id=1102 lang=cpp
 *
 * [1102] Path With Maximum Minimum Value
 */

// @lc code=start
class Solution {
public:
  // int maximumMinimumPath(vector<vector<int>> &g) {
  //   int m = g.size(), n = g[0].size();
  //   auto id = [&](int x, int y) { return x * n + y; };
  //   vector<int> p(m * n);
  //   iota(p.begin(), p.end(), 0);
  //   auto find = [&](this auto &find, int x) -> int {
  //     return x == p[x] ? x : p[x] = find(p[x]);
  //   };
  //   struct Edge {
  //     int u, v, w;
  //   };
  //   vector<Edge> v;
  //   for (int i = 0; i < m; i++)
  //     for (int j = 0; j < n; j++) {
  //       int idij = id(i, j);
  //       if (i)
  //         v.emplace_back(idij, id(i - 1, j), min(g[i][j], g[i - 1][j]));
  //       if (j)
  //         v.emplace_back(idij, id(i, j - 1), min(g[i][j], g[i][j - 1]));
  //     }
  //   sort(v.begin(), v.end(), [&](auto &e1, auto &e2) { return e1.w > e2.w; });

  //   for (auto &e : v) {
  //     int u = e.u, v = e.v, w = e.w;
  //     int pu = find(u), pv = find(v);
  //     if (pu != pv)
  //       p[pu] = pv;
  //     if (find(0) == find(id(m - 1, n - 1)))
  //       return w;
  //   }

  //   return -1;
  // }

  int maximumMinimumPath(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size();
    auto id = [&](int x, int y) { return x * n + y; };
    using PII = pair<int, int>;
    priority_queue<PII> heap;
    heap.emplace(g[0][0], 0);
    vector<bool> vis(m * n);
    vis[0] = true;
    while (heap.size()) {
      auto [dis, u] = heap.top(); heap.pop();
      if (u == id(m - 1, n - 1)) return dis;
      static int d[] = {1, 0, -1, 0, 1};
      int x = u / n, y = u % n;
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n) {
          int idxy = id(nx, ny);
          if (vis[idxy]) continue;
          vis[idxy] = true;
          heap.emplace(min(dis, g[nx][ny]), idxy);
        }
      }
    }
    return -1;
  }
};
// @lc code=end
