/*
 * @lc app=leetcode id=2307 lang=cpp
 *
 * [2307] Check for Contradictions in Equations
 */

// @lc code=start
class Solution {
public:
  bool checkContradictions(vector<vector<string>> &es, vector<double> &vs) {
    unordered_map<string, int> id;
    int idx = 0;
    for (auto &e : es)
      for (auto &t : e)
        if (id.emplace(t, idx).second) idx++;
    
    int n = idx;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    vector<double> d(n, 1.0);
    auto find = [&](this auto &&find, int x) -> int {
      if (x == p[x]) return x;
      int root = find(p[x]);
      // dx = x / p[x], dpx = p[x] / px
      d[x] *= d[p[x]];
      p[x] = root;
      return root;
    };

    static constexpr double eps = 1e-5;
    for (int i = 0; i < es.size(); i++) {
      auto &e = es[i];
      int x = id[e[0]], y = id[e[1]];
      double xy = vs[i];
      int rx = find(x), ry = find(y);
      if (rx == ry) {
        if (abs(d[x] / d[y] - xy) > eps) return true;
      } else {
        p[rx] = ry;
        d[rx] = xy * d[y] / d[x];
      }
    }

    return false;
  }
};
// @lc code=end
