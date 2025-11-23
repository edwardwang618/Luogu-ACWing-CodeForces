/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    int n = s.size();
    s = ' ' + s;
    int ne[n + 1];
    ne[1] = 0;
    for (int i = 2, j = 0; i <= n; i++) {
      while (j && s[i] != s[j + 1]) j = ne[j];
      if (s[i] == s[j + 1]) j++;
      ne[i] = j;
    }

    return ne[n] && n % (n - ne[n]) == 0;
  }
};
// @lc code=end
