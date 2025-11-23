/*
 * @lc app=leetcode id=1217 lang=cpp
 *
 * [1217] Minimum Cost to Move Chips to The Same Position
 */

// @lc code=start
class Solution {
 public:
  int minCostToMoveChips(vector<int>& v) {
    int odd_cnt = 0, even_cnt = 0;
    for (int x : v) (x % 2 ? odd_cnt : even_cnt)++;
    return min(odd_cnt, even_cnt);
  }
};
// @lc code=end
