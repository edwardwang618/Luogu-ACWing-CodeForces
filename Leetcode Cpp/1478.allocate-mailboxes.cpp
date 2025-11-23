/*
 * @lc app=leetcode id=1478 lang=cpp
 *
 * [1478] Allocate Mailboxes
 */

// @lc code=start
class Solution {
 public:
  int minDistance(vector<int>& h, int m) {
    sort(h.begin(), h.end());
    int n = h.size();
    int f[n][m + 1], cost[n][n], p[n + 1];
    memset(f, 0, sizeof f);
    p[0] = 0;
    for (int i = 0; i < n; i++) p[i + 1] = h[i] + p[i];
    for (int i = 0; i < n; i++)
      for (int j = i; j < n; j++) {
        int mid = (i + j) / 2;
        cost[i][j] =
            (i + j & 1 ^ 1) * h[mid] + p[i] + p[j + 1] - 2 * p[mid + 1];
      }

    for (int i = 0; i < n; i++) f[i][0] = 0x3f3f3f3f;
    for (int i = 1; i < n; i++)
      for (int j = 1; j <= m; j++) {
        f[i][j] = 0x3f3f3f3f;
        for (int k = 0; k <= i; k++) {
          int t = cost[k][i];
          if (k) t += f[k - 1][j - 1];
          f[i][j] = min(f[i][j], t);
        }
      }

    return f[n - 1][m];
  }
};
// @lc code=end
