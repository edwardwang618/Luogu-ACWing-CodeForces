/*
 * @lc app=leetcode id=722 lang=cpp
 *
 * [722] Remove Comments
 */

// @lc code=start
class Solution {
 public:
  vector<string> removeComments(vector<string>& v) {
    vector<string> res;
    string s;
    for (auto& str : v) s += str + '\n';
    string p;
    for (int i = 0; i < s.size();) {
      if (i + 1 < s.size() && s.substr(i, 2) == "//") {
        while (s[i] != '\n') i++;
      } else if (i + 1 < s.size() && s.substr(i, 2) == "/*") {
        i += 2;
        while (s.substr(i, 2) != "*/") i++;
        i += 2;
      } else if (s[i] == '\n') {
        if (p.size()) {
          res.push_back(p);
          p = "";
        }
        i++;
      } else
        p += s[i++];
    }

    return res;
  }
};
// @lc code=end
