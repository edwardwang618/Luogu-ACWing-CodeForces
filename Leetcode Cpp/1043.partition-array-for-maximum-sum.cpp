/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 */

// @lc code=start
class Solution {
 public:
  int maxSumAfterPartitioning(vector<int>& a, int k) {
    int n = a.size(), f[n];
    memset(f, 0, sizeof f);
    f[0] = a[0];
    for (int i = 1; i < n; i++) {
      int M = a[i];
      // 枚举最后一段的左端点
      for (int j = i; j >= 0 && i - j < k; j--) {
        M = max(M, a[j]);
        f[i] = max(f[i], (j >= 1 ? f[j - 1] : 0) + M * (i - j + 1));
      }
    }

    return f[n - 1];
  }
};
// @lc code=end
