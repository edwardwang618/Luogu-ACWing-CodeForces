/*
 * @lc app=leetcode id=685 lang=cpp
 *
 * [685] Redundant Connection II
 */

// @lc code=start
class Solution {
public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>> &es) {
    int n = es.size();
    vector<int> fa(n + 1, -1), p(n + 1);
    vector<vector<int>> res;
    iota(p.begin(), p.end(), 0);
    for (auto &e : es) {
      int from = e[0], to = e[1];
      if (~fa[to]) {
        res.push_back({fa[to], to});
        res.push_back({from, to});
        e[0] = e[1] = -1;
        break;
      }
      fa[to] = from;
    }

    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    for (auto &e : es) {
      int x = e[0], y = e[1];
      if (!~x)
        continue;
      int px = find(x), py = find(y);
      if (px == py)
        return res.size() ? res[0] : vector<int>{x, y};
      p[px] = py;
    }

    return res[1];
  }
};
// @lc code=end
