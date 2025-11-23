/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
class Solution {
 public:
  vector<int> diffWaysToCompute(string s) {
    return dfs(s);
  }

  vector<int> dfs(string s) {
    static unordered_map<string, vector<int>> mp;
    if (mp.count(s)) return mp[s];
    auto& v = mp[s];
    bool isnum = true;
    for (int i = 0; i < s.size(); i++)
      if (!isdigit(s[i])) {
        isnum = false;
        auto l = dfs(s.substr(0, i)), r = dfs(s.substr(i + 1));
        for (int x : l)
          for (int y : r) {
            if (s[i] == '+') v.push_back(x + y);
            else if (s[i] == '-') v.push_back(x - y);
            else v.push_back(x * y);
          }
      }

    if (isnum) v.push_back(stoi(s));
    return v;
  }
};
// @lc code=end
