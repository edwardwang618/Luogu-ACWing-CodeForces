/*
 * @lc app=leetcode id=1246 lang=cpp
 *
 * [1246] Palindrome Removal
 */

// @lc code=start
class Solution {
 public:
  int minimumMoves(vector<int>& A) {
    int n = A.size();
    int f[n][n];
    memset(f, 0x3f, sizeof f);
    for (int len = 1; len <= n; len++)
      for (int l = 0; l + len - 1 < n; l++) {
        int r = l + len - 1;
        if (len == 1) f[l][r] = 1;
        else if (len == 2) f[l][r] = A[l] == A[r] ? 1 : 2;
        else {
          if (A[l] == A[r]) f[l][r] = f[l + 1][r - 1];
          for (int k = l; k < r; k++)
            f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
        }
      }

    return f[0][n - 1];
  }
};
// @lc code=end
