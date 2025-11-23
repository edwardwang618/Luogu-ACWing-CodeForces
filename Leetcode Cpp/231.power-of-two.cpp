/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
 public:
  bool isPowerOfTwo(int n) { 
    return n > 0 && n == (n & -n); 
  }
};
// @lc code=end
