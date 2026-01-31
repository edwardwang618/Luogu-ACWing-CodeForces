/*
 * @lc app=leetcode id=2812 lang=cpp
 *
 * [2812] Find the Safest Path in a Grid
 */

// @lc code=start
class Solution {
 public:
  struct Edge {
    int x, y, w;
  };
  
  int maximumSafenessFactor(vector<vector<int>>& g) {
    using PII = pair<int, int>;
    int n = g.size(), nn = n * n;
    queue<PII> q;
    vector<vector<int>> s(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j]) {
          q.emplace(i, j);
          s[i][j] = 0;
        }
    static constexpr int d[]{1, 0, -1, 0, 1};
    while (q.size()) {
      auto [x, y] = q.front(); q.pop();
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
          if (~s[nx][ny]) continue;
          s[nx][ny] = s[x][y] + 1;
          q.emplace(nx, ny);
        }
      }
    }

    auto f = [&](int x, int y) { return x * n + y; };
    // vector<int> p(nn);
    // iota(p.begin(), p.end(), 0);
    // vector<Edge> es;
    // for (int i = 0; i < n; i++)
    //   for (int j = 0; j < n; j++) {
    //     if (i + 1 < n)
    //       es.emplace_back(f(i, j), f(i + 1, j), min(s[i][j], s[i + 1][j]));
    //     if (j + 1 < n)
    //       es.emplace_back(f(i, j), f(i, j + 1), min(s[i][j], s[i][j + 1]));
    //   }

    // sort(es.begin(), es.end(), [&](auto& e1, auto& e2) { return e1.w > e2.w; });
    // auto find = [&](this auto &&find, int x) -> int { 
    //   return p[x] == x ? x : p[x] = find(p[x]); 
    // };
    // auto merge = [&](int x, int y) {
    //   int px = find(x), py = find(y);
    //   p[px] = py;
    // };
    // for (auto& e : es) {
    //   int x = e.x, y = e.y, w = e.w;
    //   merge(x, y);
    //   if (find(0) == find(nn - 1)) return w;
    // }
    priority_queue<PII> heap;
    heap.emplace(s[0][0], 0);
    vector<vector<bool>> vis(n, vector<bool>(n));
    vis[0][0] = true;
    while (heap.size()) {
      auto [safe, u] = heap.top(); heap.pop();
      int x = u / n, y = u % n;
      if (x == n - 1 && y == n - 1) return safe;
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && !vis[nx][ny]) {
          heap.emplace(min(safe, s[nx][ny]), f(nx, ny));
          vis[nx][ny] = true;
        }
      }
    }

    return 0;
  }
};
// @lc code=end
