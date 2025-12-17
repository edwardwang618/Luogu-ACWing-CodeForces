/*
 * @lc app=leetcode id=2559 lang=cpp
 *
 * [2559] Count Vowel Strings in Ranges
 */

// @lc code=start
class Solution {
public:
  vector<int> vowelStrings(vector<string> &ws, vector<vector<int>> &qs) {
    vector<int> sum(ws.size() + 1);
    static constexpr auto f = [](char ch) {
      return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    };
    for (int i = 0; i < ws.size(); i++) {
      auto &s = ws[i];
      sum[i + 1] = sum[i] + (f(s[0]) && f(s.back()));
    }
    vector<int> res;
    res.reserve(qs.size());
    for (auto &v : qs)
      res.push_back(sum[v[1] + 1] - sum[v[0]]);
    return res;
  }
};
// @lc code=end
