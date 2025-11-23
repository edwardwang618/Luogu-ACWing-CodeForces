/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution {
 public:
  void gameOfLife(vector<vector<int>>& g) {
    auto f = [&](int x, int y) {
      int live = 0;
      for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++) {
          if (!i && !j) continue;
          if (0 <= x + i && x + i < g.size() && 0 <= y + j &&
              y + j < g[0].size())
            if ((g[x + i][y + j] & 1) == 1) live++;
        }
      if ((g[x][y] & 1) == 1) {
        if (2 <= live && live <= 3) g[x][y] = 3;
      } else {
        if (live == 3) g[x][y] = 2;
      }
    };
    for (int i = 0; i < g.size(); i++)
      for (int j = 0; j < g[0].size(); j++) f(i, j);
    for (int i = 0; i < g.size(); i++)
      for (int j = 0; j < g[0].size(); j++) g[i][j] >>= 1;
  }
};
// @lc code=end
