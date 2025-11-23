/*
 * @lc app=leetcode id=1362 lang=cpp
 *
 * [1362] Closest Divisors
 */

// @lc code=start
class Solution {
 public:
  vector<int> closestDivisors(int num) {
    for (int x = sqrt(num + 2); x; x--) {
      if ((num + 1) % x == 0) return {x, (num + 1) / x};
      if ((num + 2) % x == 0) return {x, (num + 2) / x};
    }

    return {};
  }
};
// @lc code=end
