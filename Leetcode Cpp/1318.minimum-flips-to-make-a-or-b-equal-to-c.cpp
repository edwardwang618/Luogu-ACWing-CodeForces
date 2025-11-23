/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 */

// @lc code=start
class Solution {
 public:
  int minFlips(int a, int b, int c) {
    int res = 0;
    while ((a | b) != c) {
      if (c & 1)
        res += !((a | b) & 1);
      else
        res += (a & 1) + (b & 1);

      c >>= 1, a >>= 1, b >>= 1;
    }

    return res;
  }
};
// @lc code=end
