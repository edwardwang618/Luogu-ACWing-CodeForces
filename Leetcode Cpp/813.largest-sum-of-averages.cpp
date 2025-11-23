/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
 */

// @lc code=start
class Solution {
 public:
  double largestSumOfAverages(vector<int>& a, int k) {
    int n = a.size();
    vector<vector<double>> f(n + 1, vector<double>(k + 1, -1e9));
    f[0][0] = 0;

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= min(i, k); j++) {
        double sum = 0;
        for (int l = i; l > j - 1; l--) {
          sum += a[l - 1];
          f[i][j] = max(f[i][j], sum / (i - l + 1) + f[l - 1][j - 1]);
        }
      }
    return f[n][k];
  }
};
// @lc code=end
