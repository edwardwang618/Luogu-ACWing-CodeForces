/*
 * @lc app=leetcode id=2272 lang=cpp
 *
 * [2272] Substring With Largest Variance
 */

// @lc code=start
class Solution {
 public:
  int largestVariance(string s) {
    int res = 0;
    unordered_set<char> st(s.begin(), s.end());
    for (char ch1 : st)
      for (char ch2 : st)
        if (ch1 != ch2) {
          int f = -0x3f3f3f3f, g = 0;
          for (int k = 0; k < s.size(); k++) {
            int x = 0;
            if (s[k] == ch1) x = 1;
            else if (s[k] == ch2) x = -1;
            if (x == 1) f = f + 1;
            else if (!~x) f = max(g - 1, -1);
            g = max(x, g + x);
            res = max(res, f);
          }
        }
    return res;
  }
};
// @lc code=end
