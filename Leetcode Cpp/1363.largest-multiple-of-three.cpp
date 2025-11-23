/*
 * @lc app=leetcode id=1363 lang=cpp
 *
 * [1363] Largest Multiple of Three
 */

// @lc code=start
class Solution {
 public:
  string largestMultipleOfThree(vector<int>& A) {
    int n = A.size();
    sort(A.begin(), A.end());
    int f[n + 1][3];
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < 3; j++)
        f[i][j] = max(f[i - 1][j], f[i - 1][(j - A[i - 1] + 9) % 3] + 1);
    if (f[n][0] < 0) return "";

    string s;
    for (int i = n, j = 0; i; i--)
      if (f[i][j] == f[i - 1][(j - A[i - 1] + 9) % 3] + 1) {
        s += to_string(A[i - 1]);
        j = (j - A[i - 1] + 9) % 3;
      }

    return s[0] == '0' ? "0" : s;
  }
};
// @lc code=end
