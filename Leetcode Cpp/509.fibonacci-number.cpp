/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
  int fib(int n) {
    static constexpr array<int, 31> f = []() {
      array<int, 31> a;
      a[0] = 0, a[1] = 1;
      for (int i = 2; i <= 30; i++)
        a[i] = a[i - 1] + a[i - 2];
      return a;
    }();
    return f[n];
  }
};
// @lc code=end
