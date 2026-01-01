/*
 * @lc app=leetcode id=1000 lang=cpp
 *
 * [1000] Minimum Cost to Merge Stones
 */

// @lc code=start
class Solution {
public:
  // int mergeStones(vector<int> &ss, int k) {
  //   int n = ss.size();
  //   if ((n - 1) % (k - 1))
  //     return -1;
  //   vector<int> sum(n + 1);
  //   for (int i = 1; i <= n; i++)
  //     sum[i] = sum[i - 1] + ss[i - 1];
  //   auto range_sum = [&](int l, int r) { return sum[r + 1] - sum[l]; };
  //   constexpr int INF = 0x3f3f3f3f;
  //   vector<vector<vector<int>>> f(
  //       n, vector<vector<int>>(n, vector<int>(k + 1, INF)));
  //   // f[l][r][s] merge ss[l:r] into s piles
  //   for (int i = 0; i < n; i++)
  //     f[i][i][1] = 0;
  //   for (int len = 2; len <= n; len++)
  //     for (int l = 0; l + len - 1 < n; l++) {
  //       int r = l + len - 1;
  //       for (int s = 2; s <= min(len, k); s++) {
  //         if ((len - s) % (k - 1))
  //           continue;
  //         for (int mid = l; mid < r; mid += k - 1)
  //           f[l][r][s] = min(f[l][r][s], f[l][mid][1] + f[mid + 1][r][s -
  //           1]);
  //       }
  //       if ((len - 1) % (k - 1) == 0)
  //         f[l][r][1] = f[l][r][k] + range_sum(l, r);
  //     }
  //   return f[0][n - 1][1];
  // }

  int mergeStones(vector<int> &ss, int k) {
    int n = ss.size();
    if ((n - 1) % (k - 1))
      return -1;
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + ss[i - 1];
    auto range_sum = [&](int l, int r) { return sum[r + 1] - sum[l]; };
    vector<vector<int>> f(n, vector<int>(n));
    for (int len = k; len <= n; len++)
      for (int l = 0; l + len - 1 < n; l++) {
        int r = l + len - 1;
        f[l][r] = INT_MAX;
        for (int mid = l; mid < r; mid += k - 1)
          f[l][r] = min(f[l][r], f[l][mid] + f[mid + 1][r]);
        if ((len - 1) % (k - 1) == 0)
          f[l][r] += range_sum(l, r);
      }
    return f[0][n - 1];
  }
};
// @lc code=end
