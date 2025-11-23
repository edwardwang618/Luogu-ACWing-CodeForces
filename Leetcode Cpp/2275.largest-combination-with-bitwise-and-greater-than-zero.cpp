/*
 * @lc app=leetcode id=2275 lang=cpp
 *
 * [2275] Largest Combination With Bitwise AND Greater Than Zero
 */

// @lc code=start
class Solution {
 public:
  int largestCombination(vector<int>& v) {
    vector<int> bits(32);
    for (auto& x : v)
      for (int i = 0; i < 32; i++)
        if (x >> i & 1) bits[i]++;

    int res = 0;
    for (auto& x : bits) res = max(res, x);
    return res;
  }
};
// @lc code=end
