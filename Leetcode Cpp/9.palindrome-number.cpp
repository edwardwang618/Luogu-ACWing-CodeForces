/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;

    long long reversedNumber = 0, n = x;
    while (n) {
      reversedNumber *= 10;
      reversedNumber += n % 10;
      n /= 10;
    }

    return (long long)x == reversedNumber;
  }
};
// @lc code=end
