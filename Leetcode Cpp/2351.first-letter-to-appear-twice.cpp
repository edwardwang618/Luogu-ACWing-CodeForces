/*
 * @lc app=leetcode id=2351 lang=cpp
 *
 * [2351] First Letter to Appear Twice
 */

// @lc code=start
class Solution {
 public:
  char repeatedCharacter(string s) {
    unordered_set<char> st;
    for (char ch : s)
      if (st.count(ch))
        return ch;
      else
        st.insert(ch);
    return ' ';
  }
};
// @lc code=end
