/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& g) {
    int f[5] = {0};
    auto in_bound = [&](int x, int y) {
      return 0 <= x && x < g.size() && 0 <= y && y < g[0].size();
    };
    for (int i = 0; i < g.size(); i++)
      for (int j = 0; j < g[0].size(); j++)
        if (g[i][j]) {
          int cnt = 0;
          for (int di = -1; di <= 1; di++)
            for (int dj = -1; dj <= 1; dj++)
              if (((!di && dj) || (di && !dj)) && in_bound(i + di, j + dj) &&
                  g[i + di][j + dj])
                cnt++;
          f[cnt]++;
        }
    int res = 0;
    for (int i = 0; i <= 4; i++) res += f[i] * (4 - i);
    return res;
  }
};
// @lc code=end
