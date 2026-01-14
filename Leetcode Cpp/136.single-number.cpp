/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
  int singleNumber(vector<int> &a) {
    int res = 0;
    for (int x : a) res ^= x;
    return res;
  }
};
// @lc code=end
