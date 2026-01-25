/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
class Solution {
public:
  int hammingDistance(int x, int y) { return popcount(unsigned(x ^ y)); }
};
// @lc code=end
