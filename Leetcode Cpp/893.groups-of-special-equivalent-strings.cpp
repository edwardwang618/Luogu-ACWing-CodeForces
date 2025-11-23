/*
 * @lc app=leetcode id=893 lang=cpp
 *
 * [893] Groups of Special-Equivalent Strings
 */

// @lc code=start
class Solution {
 public:
  int numSpecialEquivGroups(vector<string>& ws) {
    unordered_set<string> st;
    for (auto& s : ws) {
      string s1, s2;
      for (int i = 0; i < s.size(); i++) (i & 1) ? s2 += s[i] : s1 += s[i];
      sort(s1.begin(), s1.end());
      sort(s2.begin(), s2.end());
      st.insert(s1 + " " + s2);
    }
    return st.size();
  }
};
// @lc code=end
