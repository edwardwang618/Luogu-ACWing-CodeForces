/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> f(n + 1), g(n + 1);
    for (int i = 1; i <= n; i++) {
      f[i] = nums[i - 1] + g[i - 1];
      g[i] = max(f[i - 1], g[i - 1]);
    }

    return max(f[n], g[n]);
  }
};
// @lc code=end
