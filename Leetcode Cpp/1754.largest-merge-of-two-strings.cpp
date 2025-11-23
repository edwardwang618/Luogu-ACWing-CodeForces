/*
 * @lc app=leetcode id=1754 lang=cpp
 *
 * [1754] Largest Merge Of Two Strings
 */

// @lc code=start
class Solution {
 public:
  string largestMerge(string s1, string s2) {
    string s;
    for (int i = 0, j = 0; i < s1.size() || j < s2.size();)
      s += bigger(s1, s2, i, j) ? s1[i++] : s2[j++];

    return s;
  }

  bool bigger(string& s1, string& s2, int i, int j) {
    while (i < s1.size() && j < s2.size()) {
      if (s1[i] > s2[j]) return true;
      else if (s1[i] < s2[j]) return false;
      else i++, j++;
    }

    return j == s2.size();
  }
};
// @lc code=end
