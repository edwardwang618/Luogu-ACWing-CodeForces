/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
 public:
  bool isHappy(int n) {
    int slow = n, fast = n;
    do {
      slow = calc(slow);
      fast = calc(calc(fast));
    } while (fast != slow);
    
    return fast == 1;
  }

  int calc(int n) {
    int sum = 0;
    while (n) {
      sum += (n % 10) * (n % 10);
      n /= 10;
    }
    return sum;
  }
};
// @lc code=end
