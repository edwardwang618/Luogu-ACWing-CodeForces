/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 */

// @lc code=start
class Solution {
 public:
  int equalPairs(vector<vector<int>>& g) {
    int n = g.size();
    int res = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        bool flag = true;
        for (int k = 0; k < n; k++)
          if (g[i][k] != g[k][j]) {
            flag = false;
            break;
          }
        if (flag) res++;
      }
    return res;
  }
};
// @lc code=end
