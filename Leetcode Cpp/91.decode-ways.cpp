/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
 public:
  int numDecodings(string s) {
    int n = s.size();
    int f[n + 1];
    memset(f, 0, sizeof f);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
      int b = s[i - 1] - '0';
      if (1 <= b && b <= 9) f[i] += f[i - 1];
      if (i >= 2) {
        int a = s[i - 2] - '0';
        if (a == 1 || (a == 2 && b <= 6)) f[i] += f[i - 2];
      }
    }

    return f[n];
  }
};
// @lc code=end
