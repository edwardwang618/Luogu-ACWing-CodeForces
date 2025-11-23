/*
 * @lc app=leetcode id=1823 lang=cpp
 *
 * [1823] Find the Winner of the Circular Game
 */

// @lc code=start
class Solution {
 public:
  int findTheWinner(int n, int k) {
    if (n == 1) return 1;
    return (findTheWinner(n - 1, k) + k - 1) % n + 1;
  }
};
// @lc code=end
