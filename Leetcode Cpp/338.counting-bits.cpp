/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++)
      f[i] = (i & 1) + f[i >> 1];

    return f;
  }
};
// @lc code=end
