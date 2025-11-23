/*
 * @lc app=leetcode id=816 lang=cpp
 *
 * [816] Ambiguous Coordinates
 */

// @lc code=start
class Solution {
 public:
  vector<string> ambiguousCoordinates(string s) {
    s = s.substr(1, s.size() - 2);
    vector<string> res;
    auto calc = [](const string& s) {
      unordered_set<string> st;
      if (s.size() == 1 || s[0] != '0') st.insert(s);
      for (int i = 0; i + 1 < s.size(); i++) {
        auto s1 = s.substr(0, i + 1), s2 = s.substr(i + 1);
        if (s1.size() > 1 && s1[0] == '0') continue;
        if (s2.back() == '0') continue;
        st.insert(s1 + "." + s2);
      }
      return st;
    };
    for (int i = 0; i + 1 < s.size(); i++) {
      auto s1 = s.substr(0, i + 1), s2 = s.substr(i + 1);
      for (auto& t1 : calc(s1))
        for (auto& t2 : calc(s2)) res.push_back("(" + t1 + ", " + t2 + ")");
    }
    return res;
  }
};
// @lc code=end
