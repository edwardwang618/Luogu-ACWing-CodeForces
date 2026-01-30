/*
 * @lc app=leetcode id=320 lang=cpp
 *
 * [320] Generalized Abbreviation
 */

// @lc code=start
class Solution {
public:
  vector<string> generateAbbreviations(string &s) {
    int n = s.size();
    vector<string> res;
    string p;
    vector<string> nums(n + 1);
    for (int i = 1; i <= n; i++) nums[i] = to_string(i);
    auto dfs = [&](this auto &&dfs, int u) -> void {
      if (u == n) {
        res.push_back(p);
        return;
      }

      p += s[u];
      dfs(u + 1);
      p.pop_back();
  
      for (int i = u; i < n; i++) {
        if (p.size() && isdigit(p.back())) return;
        int len = i - u + 1;
        p += nums[len];
        dfs(i + 1);
        p.resize(p.size() - nums[len].size());
      }
    };
    dfs(0);
    return res;
  }
};
// @lc code=end
