/*
 * @lc app=leetcode id=1573 lang=cpp
 *
 * [1573] Number of Ways to Split a String
 */

// @lc code=start
class Solution {
 public:
  int numWays(string s) {
    const int MOD = 1e9 + 7;
    int n = s.size(), cnt = 0;
    for (char &ch : s) cnt += ch - '0';
    if (cnt % 3) return 0;

    if (!cnt) return ((long)(n - 1) * (n - 2) / 2) % MOD;

    cnt /= 3;
    int x[2];
    for (int i = 0, c = 0; i < n; i++) {
      c += s[i] - '0';
      if (c == cnt || c == cnt * 2) {
        int j = i + 1;
        while (j < n && s[j] == '0') j++;
        x[c / cnt - 1] = j - i - 1;
        i = j - 1;
      }
    }

    return ((long)(x[0] + 1) * (x[1] + 1) % MOD);
  }
};
// @lc code=end
