/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
 public:
  string simplifyPath(string s) {
    string res, file;
    if (s.back() != '/') s += '/';
    for (char ch : s) {
      if (ch != '/') file += ch;
      else {
        if (file == "..") {
          while (res.size() && res.back() != '/') res.pop_back();
          if (res.size()) res.pop_back();
        } else if (file.size() && file != ".") res += '/' + file;
        file.clear();
      }
    }

    if (res.empty()) return "/";
    return res;
  }
};
// @lc code=end
