/*
 * @lc app=leetcode id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 */

// @lc code=start
class Solution {
 public:
  int numTilePossibilities(string s) {
    sort(s.begin(), s.end());
    int res = 0;
    dfs(0, s, res);
    return res - 1;
  }

  void dfs(int u, string& s, int& res) {
    res++;
    if (u == s.size()) return;

    for (int i = 0; i < s.size(); i++) {
      if (i && s[i] == s[i - 1] && s[i - 1] != ' ') continue;
      if (s[i] == ' ') continue;
      char ch = s[i];
      s[i] = ' ';
      dfs(u + 1, s, res);
      s[i] = ch;
    }
  }
};
// @lc code=end
