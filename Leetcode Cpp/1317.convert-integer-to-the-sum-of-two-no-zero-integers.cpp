/*
 * @lc app=leetcode id=1317 lang=cpp
 *
 * [1317] Convert Integer to the Sum of Two No-Zero Integers
 */

// @lc code=start
class Solution {
 public:
  vector<int> getNoZeroIntegers(int n) {
    auto f = [](int x) {
      while (x) {
        if (x % 10 == 0) return false;
        x /= 10;
      }
      return true;
    };
    for (int i = 1; i <= n / 2; i++) {
      int j = n - i;
      if (f(i) && f(j)) return {i, j};
    }

    return {};
  }
};
// @lc code=end
