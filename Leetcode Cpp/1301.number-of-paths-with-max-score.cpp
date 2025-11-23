/*
 * @lc app=leetcode id=1301 lang=cpp
 *
 * [1301] Number of Paths with Max Score
 */

// @lc code=start
class Solution {
 public:
  vector<int> pathsWithMaxScore(vector<string>& h) {
    int m = h.size(), n = h[0].size();
    h[m - 1][n - 1] = '0';
    int f[m][n], g[m][n];
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    g[0][0] = 1;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (!i && !j || h[i][j] == 'X') continue;
        int max_s = 0, cnt = 0;
        if (i && g[i - 1][j])
          update(h[i][j], f[i - 1][j], g[i - 1][j], max_s, cnt);
        if (j && g[i][j - 1])
          update(h[i][j], f[i][j - 1], g[i][j - 1], max_s, cnt);
        if (i && j && g[i - 1][j - 1])
          update(h[i][j], f[i - 1][j - 1], g[i - 1][j - 1], max_s, cnt);
        f[i][j] = max_s, g[i][j] = cnt;
      }

    return {f[m - 1][n - 1], g[m - 1][n - 1]};
  }

  void update(char ch, int pre_score, int pre_cnt, int& max_s, int& cnt) {
    int x = ch - '0' + pre_score;
    if (max_s < x) max_s = x, cnt = pre_cnt;
    else if (max_s == x) cnt = (cnt + pre_cnt) % int(1e9 + 7);
  }
};
// @lc code=end
