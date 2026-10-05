/*
 * @lc app=leetcode id=1168 lang=cpp
 *
 * [1168] Optimize Water Distribution in a Village
 */

// @lc code=start
class Solution {
public:
  int minCostToSupplyWater(int n, vector<int> &ws, vector<vector<int>> &ps) {
    vector<int> p(n + 2);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    struct Edge {
      int u, v, w;
    };
    vector<Edge> es;
    es.reserve(n + ps.size());
    for (int i = 0; i < n; i++)
      es.push_back(Edge{0, i + 1, ws[i]});
    for (auto &pipe : ps)
      es.push_back(Edge{pipe[0], pipe[1], pipe[2]});
    sort(es.begin(), es.end(), [](auto &a, auto &b) { return a.w < b.w; });
    int res = 0;
    for (auto &e : es) {
      int pu = find(e.u), pv = find(e.v), w = e.w;
      if (pu == pv)
        continue;
      p[pu] = pv;
      res += w;
    }
    return res;
  }
};
// @lc code=end
