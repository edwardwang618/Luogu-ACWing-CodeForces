/*
 * @lc app=leetcode id=1276 lang=cpp
 *
 * [1276] Number of Burgers with No Waste of Ingredients
 */

// @lc code=start
class Solution {
 public:
  vector<int> numOfBurgers(int t, int c) {
    int x = t - 2 * c;
    if (x % 2) return {};
    x /= 2;
    if (x < 0 || x > c) return {};
    return {x, c - x};
  }
};
// @lc code=end
