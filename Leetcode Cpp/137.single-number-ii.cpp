/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution {
public:
  int singleNumber(vector<int> &a) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
      int x = 0;
      for (int c : a)
        x += c >> i & 1;
      if (x % 3)
        res |= 1 << i;
    }

    return res;
  }
};
// @lc code=end
