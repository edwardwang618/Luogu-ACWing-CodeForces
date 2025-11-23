/*
 * @lc app=leetcode id=1884 lang=cpp
 *
 * [1884] Egg Drop With 2 Eggs and N Floors
 */

// @lc code=start
class Solution {
 public:
  int twoEggDrop(int n) {
    int res = 1, tot = 1;
    while (tot < n) tot += ++res;
    return res;
  }
};
// @lc code=end
