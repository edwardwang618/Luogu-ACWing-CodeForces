/*
 * @lc app=leetcode id=1023 lang=cpp
 *
 * [1023] Camelcase Matching
 */

// @lc code=start
class Solution {
 public:
  vector<bool> camelMatch(vector<string>& qs, string p) {
    vector<bool> res;
    auto check = [&](string& s) {
      int j = 0;
      for (int i = 0; i < s.size(); i++)
        if (j < p.size() && s[i] == p[j]) j++;
        else if (isupper(s[i])) return false;
      return j == p.size();
    };
    for (auto& s : qs) res.push_back(check(s));
    return res;
  }
};
// @lc code=end
