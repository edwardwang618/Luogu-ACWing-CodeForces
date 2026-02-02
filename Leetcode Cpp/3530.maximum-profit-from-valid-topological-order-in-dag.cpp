/*
 * @lc app=leetcode id=3530 lang=cpp
 *
 * [3530] Maximum Profit from Valid Topological Order in DAG
 */

// @lc code=start
class Solution {
public:
  int maxProfit(int n, vector<vector<int>> &es, vector<int> &s) {
    vector<int> pre(n);
    for (auto &e : es) pre[e[1]] |= 1 << e[0];
    const int FULL = (1 << n) - 1;
    vector<int> f(FULL + 1, -1);
    f[0] = 0;
    for (int mask = 0; mask < FULL; mask++) {
      if (!~f[mask]) continue;
      int mult = popcount(unsigned(mask)) + 1;
      for (int ne = 0; ne < n; ne++) {
        if (mask >> ne & 1) continue;
        if ((pre[ne] & mask) != pre[ne]) continue;
        int nmask = mask ^ (1 << ne);
        f[nmask] = max(f[nmask], f[mask] + mult * s[ne]);
      }
    }
    return f[FULL];
  }
};
// @lc code=end
