/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
class Solution {
 public:
#define lowbit(x) ((x) & (-x))
  vector<int> singleNumber(vector<int>& nums) {
    int cur = 0;
    for (int x : nums) cur ^= x;
    int n1 = cur, n2 = cur;
    int lowb = lowbit((long)cur);
    for (int x : nums) (lowb & x) ? n1 ^= x : n2 ^= x;

    return {n1, n2};
  }
};
// @lc code=end
