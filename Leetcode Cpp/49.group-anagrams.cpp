/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& ss) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> mp;
    for (auto& s : ss) {
      auto t = s;
      sort(t.begin(), t.end());
      mp[t].push_back(std::move(s));
    }

    for (auto& [k, v] : mp) res.push_back(std::move(v));
    return res;
  }
};
// @lc code=end
