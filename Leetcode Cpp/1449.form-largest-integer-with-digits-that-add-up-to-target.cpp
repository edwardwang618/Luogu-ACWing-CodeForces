/*
 * @lc app=leetcode id=1449 lang=cpp
 *
 * [1449] Form Largest Integer With Digits That Add up to Target
 */

// @lc code=start
class Solution {
 public:
  string largestNumber(vector<int>& cost, int target) {
    int f[10][target + 1];
    memset(f, -1, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= 9; i++)
      for (int j = 0; j <= target; j++) {
        f[i][j] = f[i - 1][j];
        if (j >= cost[i - 1] && ~f[i][j - cost[i - 1]])
          f[i][j] = max(f[i][j], f[i][j - cost[i - 1]] + 1);
      }

    if (f[9][target] == -1) return "0";

    string res;
    for (int i = 9, j = target; i; i--)
      while (j >= cost[i - 1] && f[i][j] == f[i][j - cost[i - 1]] + 1) {
        res += to_string(i);
        j -= cost[i - 1];
      }

    return res;
  }
};
// @lc code=end
