/*
 * @lc app=leetcode id=351 lang=cpp
 *
 * [351] Android Unlock Patterns
 */

// @lc code=start
class Solution {
public:
  int numberOfPatterns(int m, int n) {
    int cr[10][10] = {0};
    cr[1][3] = cr[3][1] = 2;
    cr[1][7] = cr[7][1] = 4;
    cr[1][9] = cr[9][1] = 5;
    cr[2][8] = cr[8][2] = 5;
    cr[3][7] = cr[7][3] = 5;
    cr[3][9] = cr[9][3] = 6;
    cr[4][6] = cr[6][4] = 5;
    cr[7][9] = cr[9][7] = 8;
    vector<vector<int>> f(1 << 9, vector<int>(9));
    for (int i = 0; i < 9; i++) f[1 << i][i] = 1;

    int res = 0;
    for (int s = 1; s < (1 << 9); s++) {
      int len = __builtin_popcount(s);
      for (int cur = 0; cur < 9; cur++) {
        if (!(s >> cur & 1)) continue;
        if (!f[s][cur]) continue;
        if (m <= len && len <= n) res += f[s][cur];
        if (len >= n) continue;
        for (int ne = 0; ne < 9; ne++) {
          if (s >> ne & 1) continue;
          int c = cr[cur + 1][ne + 1];
          if (c && !(s >> c - 1 & 1)) continue;
          f[s | (1 << ne)][ne] += f[s][cur];
        }
      }
    }
    return res;
  }
};
// @lc code=end
