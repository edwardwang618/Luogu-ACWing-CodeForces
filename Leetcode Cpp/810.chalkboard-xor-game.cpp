/*
 * @lc app=leetcode id=810 lang=cpp
 *
 * [810] Chalkboard XOR Game
 */

// @lc code=start
class Solution {
public:
  bool xorGame(vector<int> &a) {
    int x = 0;
    for (int y : a)
      x ^= y;
    return !x || a.size() % 2 == 0;
  }
};
// @lc code=end
