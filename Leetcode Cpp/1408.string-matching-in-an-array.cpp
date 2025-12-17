/*
 * @lc app=leetcode id=1408 lang=cpp
 *
 * [1408] String Matching in an Array
 */

// @lc code=start
class Solution {
public:
  vector<string> stringMatching(vector<string> &ws) {
    int n = ws.size();
    vector<string> res;
    sort(ws.begin(), ws.end(),
         [&](auto &s1, auto &s2) { return s1.size() < s2.size(); });
    auto kmp = [&](auto& s, auto& p) {
      if (s[0] != ' ') s = " " + s;
      if (p[0] != ' ') p = " " + p;
      int m = p.size() - 1, n = s.size() - 1;
      vector<int> ne(m + 1);
      for (int i = 2, j = 0; i <= m; i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
      }
      for (int i = 1, j = 0; i <= n; i++) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == m) return true;
      }
      return false;
    };
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (kmp(ws[j], ws[i])) {
          res.push_back(ws[i].substr(1));
          break;
        }
    
    return res;
  }
};
// @lc code=end
