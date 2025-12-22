/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
class Solution {
public:
  int maxCoins(vector<int> &a) {
    int n = a.size();
    a.insert(a.begin(), 1);
    a.push_back(1);
    vector<vector<int>> f(n + 2, vector<int>(n + 2));
    for (int len = 1; len <= n; len++)
      for (int l = 1; l + len - 1 <= n; l++) {
        int r = l + len - 1;
        if (len == 1)
          f[l][r] = a[l - 1] * a[l] * a[l + 1];
        else {
          for (int k = l; k <= r; k++)
            f[l][r] = max(f[l][r], f[l][k - 1] + f[k + 1][r] +
                                       a[l - 1] * a[k] * a[r + 1]);
        }
      }
    return f[1][n];
  }
};
// @lc code=end
