/*
 * @lc app=leetcode id=2436 lang=cpp
 *
 * [2436] Minimum Split Into Subarrays With GCD Greater Than One
 */

// @lc code=start
class Solution {
 public:
  int minimumSplits(vector<int>& a) {
    int res = 1, x = a[0];
    for (int y : a)
      if (gcd(x, y) == 1) {
        res++;
        x = y;
      } else x = gcd(x, y);
    
    return res;
  }

  int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
  }
};
// @lc code=end
