/*
 * @lc app=leetcode id=1627 lang=cpp
 *
 * [1627] Graph Connectivity With Threshold
 */

// @lc code=start
class Solution {
 public:
  vector<bool> areConnected(int n, int td, vector<vector<int>>& qs) {
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) p[i] = i;

    function<int(int)> find = [&](int x) -> int {
      if (x != p[x]) p[x] = find(p[x]);
      return p[x];
    };

    for (int d = td + 1; d <= n; d++)
      for (int k = d * 2; k <= n; k += d) p[find(d)] = p[find(k)];

    vector<bool> res;
    for (auto& q : qs) {
      int x = q[0], y = q[1];
      res.push_back(find(x) == find(y));
    }
    return res;
  }
};
// @lc code=end
