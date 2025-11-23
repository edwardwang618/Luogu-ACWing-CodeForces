/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  int uniquePaths(int m, int n) {
    m--, n--;
    ll res = 1;
    int k = min(m, n);
    for (int i = 0; i < k; i++) {
      res *= m + n - i;
      res /= i + 1;
    }
    return (int)res;
  }
};
// @lc code=end
