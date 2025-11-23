/*
 * @lc app=leetcode id=1759 lang=cpp
 *
 * [1759] Count Number of Homogenous Substrings
 */

// @lc code=start
class Solution {
 public:
  int countHomogenous(string s) {
    const int MOD = 1e9 + 7;
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      int j = i;
      while (j < s.size() && s[i] == s[j]) j++;
      int cnt = j - i;
      res = (res + (long)cnt * (cnt + 1) / 2) % MOD;
      i = j - 1;
    }

    return res;
  }
};
// @lc code=end
