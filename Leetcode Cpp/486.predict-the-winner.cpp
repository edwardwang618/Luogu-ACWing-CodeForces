/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution {
public:
  // bool predictTheWinner(vector<int> &a) {
  //   int n = a.size();
  //   if (n == 1 || n % 2 == 0) return true;
  //   vector<vector<int>> f(n, vector<int>(n, -1));
  //   auto dfs = [&](this auto &&dfs, int l, int r) -> int {
  //     if (~f[l][r]) return f[l][r];
  //     if (l == r) return f[l][l] = a[l];
  //     int diff1 = a[l] - dfs(l + 1, r);
  //     int diff2 = a[r] - dfs(l, r - 1);
  //     return f[l][r] = max(diff1, diff2);
  //   };
  //   return dfs(0, n - 1) >= 0;
  // }

  bool predictTheWinner(vector<int> &a) {
    int n = a.size();
    if (n == 1 || n % 2 == 0) return true;
    vector<vector<int>> f(2, vector<int>(n));
    for (int l = n - 1; l >= 0; l--)
      for (int r = l; r < n; r++) {
        int len = r - l + 1;
        if (len == 1) f[l & 1][r] = a[l];
        else f[l & 1][r] = max(a[l] - f[l + 1 & 1][r], a[r] - f[l & 1][r - 1]);
      }
    return f[0][n - 1] >= 0;
  }
};
// @lc code=end
