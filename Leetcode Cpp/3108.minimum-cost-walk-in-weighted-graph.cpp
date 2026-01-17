/*
 * @lc app=leetcode id=3108 lang=cpp
 *
 * [3108] Minimum Cost Walk in Weighted Graph
 */

// @lc code=start
class Solution {
public:
  vector<int> minimumCost(int n, vector<vector<int>> &es,
                          vector<vector<int>> &qs) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    vector<int> w(n, -1);
    for (auto &e : es) {
      int pa = find(e[0]), pb = find(e[1]);
      if (pa != pb) p[pa] = pb, w[pb] &= w[pa];
      w[pb] &= e[2];
    }
    
    int m = qs.size();
    vector<int> res(m);
    for (int i = 0; i < m; i++) {
      auto &q = qs[i];
      int u = find(q[0]), v = find(q[1]);
      res[i] = u == v ? w[u] : -1;
    }
    return res;
  }
};
// @lc code=end
