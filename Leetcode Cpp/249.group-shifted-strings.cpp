/*
 * @lc app=leetcode id=249 lang=cpp
 *
 * [249] Group Shifted Strings
 */

// @lc code=start
class Solution {
 public:
  vector<vector<string>> groupStrings(vector<string>& ss) {
    unordered_map<string, vector<string>> mp;
    for (auto& s : ss) {
      auto t = s;
      if (t[0] != 'a') {
        int diff = t[0] - 'a';
        for (int j = 0; j < t.size(); j++) {
          t[j] -= diff;
          if (t[j] < 'a') t[j] += 26;
        }
      }

      mp[t].push_back(s);
    }

    vector<vector<string>> res;
    for (auto& [k, v] : mp) res.push_back(v);
    return res;
  }
};
// @lc code=end
