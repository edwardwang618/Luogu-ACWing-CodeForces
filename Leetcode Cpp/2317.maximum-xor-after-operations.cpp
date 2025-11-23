/*
 * @lc app=leetcode id=2317 lang=cpp
 *
 * [2317] Maximum XOR After Operations
 */

// @lc code=start
class Solution {
 public:
  int maximumXOR(vector<int>& nums) {
    int res = 0;
    for (int x : nums) res |= x;
    return res;
  }
};
// @lc code=end
