/*
 * @lc app=leetcode id=1494 lang=cpp
 *
 * [1494] Parallel Courses II
 */

// @lc code=start
class Solution {
 public:
  int minNumberOfSemesters(int n, vector<vector<int>>& rs, int k) {
    vector<int> f(1 << n, n), pre(n);
    for (auto& r : rs) pre[r[1] - 1] |= 1 << r[0] - 1;

    f[0] = 0;
    for (int i = 0; i < (1 << n); i++) {
      int can_take = 0;
      for (int j = 0; j < n; j++)
        if ((pre[j] & i) == pre[j]) can_take |= 1 << j;

      can_take &= ~i;
      for (int p = can_take; p; p = p - 1 & can_take)
        if (__builtin_popcount(p) <= k) f[i | p] = min(f[i | p], f[i] + 1);
    }

    return f[(1 << n) - 1];
  }
};
// @lc code=end
