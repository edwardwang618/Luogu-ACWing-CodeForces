/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    int n = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') continue;
      int j = i, l = n;
      while (j < s.size() && s[j] != ' ') s[n++] = s[j++];
      for (int r = n - 1; l < r; l++, r--) swap(s[l], s[r]);
      s[n++] = ' ';
      i = j;
    }
    s.resize(n - 1);
    reverse(s.begin(), s.end());
    return s;
  }
};
// @lc code=end
