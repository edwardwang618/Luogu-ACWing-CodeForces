/*
 * @lc app=leetcode id=2068 lang=cpp
 *
 * [2068] Check Whether Two Strings are Almost Equivalent
 */

// @lc code=start
class Solution {
 public:
  bool checkAlmostEquivalent(string s1, string s2) {
    int cnt1[26] = {0}, cnt2[26] = {0};
    for (char ch : s1) cnt1[ch - 'a']++;
    for (char ch : s2) cnt2[ch - 'a']++;
    for (int i = 0; i < 26; i++)
      if (abs(cnt1[i] - cnt2[i]) > 3) return false;
    return true;
  }
};
// @lc code=end
