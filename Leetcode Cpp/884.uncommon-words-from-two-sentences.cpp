/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */

// @lc code=start
class Solution {
public:
  vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string, int> mp;
    auto f = [&](string &s) {
      stringstream ss(s);
      string w;
      while (ss >> w) ++mp[w];
    };
    f(s1);
    f(s2);
    vector<string> res;
    for (auto [k, v] : mp) if (v == 1) res.push_back(k);
    return res;
  }
};
// @lc code=end
