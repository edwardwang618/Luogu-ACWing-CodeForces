/*
 * @lc app=leetcode id=1979 lang=cpp
 *
 * [1979] Find Greatest Common Divisor of Array
 */

// @lc code=start
#include <limits>
class Solution {
public:
  int findGCD(vector<int> &a) {
    int x = numeric_limits<int>::max(), y = numeric_limits<int>::min();
    for (int z : a)
      x = min(x, z), y = max(y, z);

    return [&](int x, int y) {
      while (y) {
        x %= y;
        swap(x, y);
      }
      return x;
    }(x, y);
  }
};
// @lc code=end
