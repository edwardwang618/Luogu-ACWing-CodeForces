/*
 * @lc app=leetcode id=1320 lang=cpp
 *
 * [1320] Minimum Distance to Type a Word Using Two Fingers
 */

// @lc code=start
class Solution {
 public:
  int minimumDistance(string s) {
    int n = s.size();
    auto dist = [&](int x, int y) {
      return abs(x / 6 - y / 6) + abs(x % 6 - y % 6);
    };

    int f[n + 1][26][26];
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < 26; j++) f[0][i][j] = 0;

    for (int i = 0; i < n; i++) {
      int pos = s[i] - 'A';
      for (int x = 0; x < 26; x++)
        for (int y = 0; y < 26; y++) {
          f[i + 1][pos][y] = min(f[i + 1][pos][y], f[i][x][y] + dist(x, pos));
          f[i + 1][x][pos] = min(f[i + 1][x][pos], f[i][x][y] + dist(y, pos));
        }
    }

    int res = 0x3f3f3f3f;
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < 26; j++) res = min(res, f[n][i][j]);
    return res;
  }
};
// @lc code=end
