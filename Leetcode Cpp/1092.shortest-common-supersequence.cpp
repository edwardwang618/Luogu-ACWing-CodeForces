/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence
 */

// @lc code=start
class Solution {
 public:
  string shortestCommonSupersequence(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    s1 = " " + s1;
    s2 = " " + s2;
    int f[m + 1][n + 1];
    memset(f, 0, sizeof f);
    for (int i = 0; i <= n; i++) f[0][i] = i;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) {
        if (s1[i] == s2[j]) f[i][j] = f[i - 1][j - 1];
        else f[i][j] = min(f[i - 1][j], f[i][j - 1] + 1);
      }
    
    string res;
    for (int i = m, j = n; i;) {
      if (s1[i] == s2[j]) {
        res.push_back(s2[j--]);
        i--;
      } else {
        if (f[i][j] == f[i - 1][j]) res.push_back(s1[i--]);
        else res.push_back(s2[j--]);
      }
      if (!i) while (j) res.push_back(s2[j--]);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
