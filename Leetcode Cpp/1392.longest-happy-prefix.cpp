/*
 * @lc app=leetcode id=1392 lang=cpp
 *
 * [1392] Longest Happy Prefix
 */

// @lc code=start
class Solution {
 public:
  string longestPrefix(string s) {
    int n = s.size();
    s = " " + s;
    int ne[n + 1];
    ne[1] = 0;
    for (int i = 2, j = 0; i <= n; i++) {
      while (j && s[i] != s[j + 1]) j = ne[j];
      if (s[i] == s[j + 1]) j++;
      ne[i] = j;
    }

    return s.substr(1, ne[n]);
  }
};
// @lc code=end
