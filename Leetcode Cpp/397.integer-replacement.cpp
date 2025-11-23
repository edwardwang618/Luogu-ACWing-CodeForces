/*
 * @lc app=leetcode id=397 lang=cpp
 *
 * [397] Integer Replacement
 */

// @lc code=start
class Solution {
 public:
  int integerReplacement(int n) {
    if (n == 1) return 0;
    if (n % 2 == 0) return 1 + integerReplacement(n / 2);
    if (n == INT_MAX) return 32;
    return 1 + min(integerReplacement(n - 1), integerReplacement(n + 1));
  }
};
// @lc code=end
