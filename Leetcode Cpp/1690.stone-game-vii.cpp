/*
 * @lc app=leetcode id=1690 lang=cpp
 *
 * [1690] Stone Game VII
 */

// @lc code=start
class Solution {
public:
  int stoneGameVII(vector<int> &a) {
    int n = a.size();
    vector<int> s(n + 1);
    for (int i = 0; i < n; i++)
      s[i + 1] = s[i] + a[i];
    auto sum = [&](int l, int r) { return s[r + 1] - s[l]; };
    vector<vector<int>> f(2, vector<int>(n));
    for (int l = n - 1; l >= 0; l--)
      for (int r = l + 1; r < n; r++)
        f[l & 1][r] = max(sum(l + 1, r) - f[l + 1 & 1][r],
                          sum(l, r - 1) - f[l & 1][r - 1]);

    return f[0][n - 1];
  }
};
// @lc code=end
