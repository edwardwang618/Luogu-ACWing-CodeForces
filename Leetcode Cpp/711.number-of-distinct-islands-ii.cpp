/*
 * @lc app=leetcode id=711 lang=cpp
 *
 * [711] Number of Distinct Islands II
 */

// @lc code=start
class Solution {
public:
  int numDistinctIslands2(vector<vector<int>> &g) {
    using PII = pair<int, int>;
    int m = g.size(), n = g[0].size();
    auto get_hash = [&](vector<PII> &v) {
      double h = 0;
      int sz = v.size();
      for (int i = 0; i < sz; i++)
        for (int j = i + 1; j < sz; j++) {
          auto [x1, y1] = v[i];
          auto [x2, y2] = v[j];
          int dx = x1 - x2, dy = y1 - y2;
          h += sqrt(dx * dx + dy * dy);
        }
      return h;
    };
    auto dfs = [&](this auto &&dfs, int x, int y, vector<PII> &v) -> void {
      g[x][y] = 0;
      v.emplace_back(x, y);
      static constexpr int d[]{-1, 0, 1, 0, -1};
      for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[i + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny])
          dfs(nx, ny, v);
      }
    };

    static constexpr double eps = 1e-10;
    set<double, decltype([](double a, double b) {
      if (abs(a - b) < eps) return false;
        return a < b;
      })> hashs;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j]) {
          vector<PII> v;
          dfs(i, j, v);
          hashs.insert(get_hash(v));
        }

    return hashs.size();
  }
};
// @lc code=end
