/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> f(m + 1, vector<int>(n + 1));
    for (auto& s : strs) {
      int n0 = 0, n1 = 0;
      for (auto& ch : s)
        if (ch == '0') n0++;
        else n1++;
      
      for (int i = m; i >= n0; i--)
        for (int j = n; j >= n1; j--)
          f[i][j] = max(f[i][j], f[i - n0][j - n1] + 1);
    }

    return f[m][n];
  }
};
// @lc code=end
