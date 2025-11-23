/*
 * @lc app=leetcode id=477 lang=cpp
 *
 * [477] Total Hamming Distance
 */

// @lc code=start
class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int f[2][32] = {0};
    for (auto& x : nums)
      for (int i = 0; i < 32; i++) f[x >> i & 1][i]++;

    int res = 0;
    for (int i = 0; i < 32; i++) res += f[0][i] * f[1][i];
    return res;
  }
};
// @lc code=end
