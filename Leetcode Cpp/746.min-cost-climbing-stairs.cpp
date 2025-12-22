/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
  int minCostClimbingStairs(vector<int> &c) {
    int n = c.size();
    vector<int> f(3);
    for (int i = 2; i <= n; i++)
      f[i % 3] = min(f[(i - 1) % 3] + c[i - 1], f[(i - 2) % 3] + c[i - 2]);
    return f[n % 3];
  }
};
// @lc code=end
