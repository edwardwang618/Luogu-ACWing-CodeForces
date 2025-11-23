/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
class Solution {
 public:
  string mergeAlternately(string s1, string s2) {
    string res;
    for (int i = 0, j = 0; i < s1.size() || j < s2.size();) {
      if (i < s1.size()) res += s1[i++];
      if (j < s2.size()) res += s2[j++];
    }
    return res;
  }
};
// @lc code=end
