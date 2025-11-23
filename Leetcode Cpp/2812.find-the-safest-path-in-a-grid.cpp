/*
 * @lc app=leetcode id=2812 lang=cpp
 *
 * [2812] Find the Safest Path in a Grid
 */

// @lc code=start
class Solution {
 public:
  using PII = pair<int, int>;
  struct Edge {
    int x, y, w;
  };
  vector<int> p;
  int maximumSafenessFactor(vector<vector<int>>& g) {
    int n = g.size(), nn = n * n;
    p.resize(nn);
    for (int i = 0; i < nn; i++) p[i] = i;
    queue<PII> q;
    vector<vector<int>> s(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j]) {
          q.push({i, j});
          s[i][j] = 0;
        }
    static int d[] = {-1, 0, 1, 0, -1};
    while (q.size()) {
      auto t = q.front();
      q.pop();
      int x = t.first, y = t.second;
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
          if (~s[nx][ny]) continue;
          s[nx][ny] = s[x][y] + 1;
          q.push({nx, ny});
        }
      }
    }

    auto f = [&](int x, int y) { return x * n + y; };
    vector<Edge> es;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        if (i + 1 < n)
          es.push_back({f(i, j), f(i + 1, j), min(s[i][j], s[i + 1][j])});
        if (j + 1 < n)
          es.push_back({f(i, j), f(i, j + 1), min(s[i][j], s[i][j + 1])});
      }

    sort(es.begin(), es.end(), [&](auto& e1, auto& e2) { return e1.w > e2.w; });

    auto merge = [&](int x, int y) {
      int px = find(x), py = find(y);
      p[px] = py;
    };
    for (auto& e : es) {
      int x = e.x, y = e.y, w = e.w;
      merge(x, y);
      if (find(0) == find(nn - 1)) return w;
    }

    return 0;
  }

  int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
};
// @lc code=end
