/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
class Solution {
 public:
  int longestStrChain(vector<string>& ws) {
    sort(ws.begin(), ws.end(),
         [&](string& s1, string& s2) { return s1.size() < s2.size(); });

    int n = ws.size();
    int f[n];
    fill(f, f + n, 1);
    auto check = [&](int i, int j) {
      auto &s1 = ws[i], &s2 = ws[j];
      if (s1.size() + 1 != s2.size()) return false;
      for (i = 0, j = 0; j < s2.size(); j++)
        if (s1[i] == s2[j]) i++;
      return i == s1.size();
    };

    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++)
        if (check(i, j)) f[j] = max(f[j], f[i] + 1);
      res = max(res, f[i]);
    }

    return res;
  }
};
// @lc code=end
