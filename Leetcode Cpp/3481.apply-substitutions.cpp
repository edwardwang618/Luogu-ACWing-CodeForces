/*
 * @lc app=leetcode id=3481 lang=cpp
 *
 * [3481] Apply Substitutions
 */

// @lc code=start
class Solution {
public:
  string applySubstitutions(vector<vector<string>> &rs, string &s) {
    unordered_map<string, string> mp;
    for (auto &r : rs) mp[r[0]] = r[1];

    unordered_map<string, string> f;
    auto exp = [&](this auto &&exp, string &s) -> string {
      string res;
      int n = s.size();
      for (int i = 0; i < n; i++) {
        if (s[i] == '%') {
          int j = i + 1;
          while (j < n && s[j] != '%') j++;
          string t = s.substr(i + 1, j - i - 1);
          string &rep = f[t];
          if (rep.empty()) rep = exp(mp[t]);
          res += rep;
          i = j;
        } else res += s[i];
      }
      return res;
    };
    return exp(s);
  }
};
// @lc code=end
