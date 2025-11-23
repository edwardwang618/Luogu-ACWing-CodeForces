/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
 public:
  string longestCommonPrefix(vector<string>& ss) {
    string res;
    for (int i = 0;; i++) {
      if (i > ss[0].size()) return res;
      char ch = ss[0][i];
      for (auto& s : ss)
        if (s.size() <= i || s[i] != ch) return res;
      res += ch;
    }
    return res;
  }
};
// @lc code=end
