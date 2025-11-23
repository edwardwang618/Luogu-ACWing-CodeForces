/*
 * @lc app=leetcode id=1003 lang=cpp
 *
 * [1003] Check If Word Is Valid After Substitutions
 */

// @lc code=start
class Solution {
 public:
  bool isValid(string s) {
    if (s.size() % 3) return false;
    string t;
    for (char ch : s) {
      t += ch;
      if (t.size() >= 3 && t.substr(t.size() - 3) == "abc")
        t.resize(t.size() - 3);
    }

    return t.empty();
  }
};
// @lc code=end
