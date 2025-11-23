/*
 * @lc app=leetcode id=1250 lang=cpp
 *
 * [1250] Check If It Is a Good Array
 */

// @lc code=start
class Solution {
 public:
  bool isGoodArray(vector<int>& nums) {
    int x = nums[0];
    for (int a : nums) {
      x = gcd(x, a);
      if (x == 1) return true;
    }

    return false;
  }

  int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
  }
};
// @lc code=end
