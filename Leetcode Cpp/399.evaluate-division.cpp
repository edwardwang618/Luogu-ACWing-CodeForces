/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
public:
  vector<double> calcEquation(vector<vector<string>> &es, vector<double> &vs,
                              vector<vector<string>> &qs) {
    unordered_map<string, int> mp;
    int n = 0;
    for (auto &e : es) {
      mp.try_emplace(e[0], n++);
      mp.try_emplace(e[1], n++);
    }

    constexpr double eps = 1e-6;
    auto is_zero = [&](double x) { return abs(x) <= eps; };
    vector<vector<double>> g(n, vector<double>(n));
    for (int i = 0; i < es.size(); i++) {
      auto &e = es[i];
      double val = vs[i];
      int x = mp[e[0]], y = mp[e[1]];
      g[x][x] = g[y][y] = 1.0;
      g[x][y] = val;
      g[y][x] = 1.0 / val;
    }

    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (!is_zero(g[i][k]) && !is_zero(g[k][j]))
            g[i][j] = g[i][k] * g[k][j];

    vector<double> res;
    res.reserve(qs.size());
    for (auto &q : qs) {
      auto &sx = q[0], &sy = q[1];
      auto itx = mp.find(sx), ity = mp.find(sy);
      if (itx == mp.end() || ity == mp.end()) {
        res.push_back(-1.0);
        continue;
      }
      int x = itx->second, y = ity->second;
      res.push_back(is_zero(g[x][y]) ? -1.0 : g[x][y]);
    }
    return res;
  }
};
// @lc code=end
