/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 */

// @lc code=start
class Solution {
 public:
  int findNumbers(vector<int>& nums) {
    int res = 0;
    for (auto x : nums) {
      int len = 0;
      while (x) x /= 10, len++;
      if (len % 2 == 0) res++;
    }
    return res;
  }
};
// @lc code=end
