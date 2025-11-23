/*
 * @lc app=leetcode id=811 lang=cpp
 *
 * [811] Subdomain Visit Count
 */

// @lc code=start
class Solution {
 public:
  vector<string> subdomainVisits(vector<string>& v) {
    unordered_map<string, int> mp;
    for (auto& s : v) {
      int k = s.find(' ');
      int cnt = stoi(s.substr(0, k));
      for (int i = s.size() - 1; i >= 0; i--)
        if (s[i] == '.' || s[i] == ' ') {
          mp[s.substr(i + 1)] += cnt;
          if (s[i] == ' ') break;
        }
    }

    vector<string> res;
    for (auto& [k, v] : mp) res.push_back(to_string(v) + ' ' + k);
    return res;
  }
};
// @lc code=end
