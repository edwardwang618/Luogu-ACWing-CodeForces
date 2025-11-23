/*
 * @lc app=leetcode id=531 lang=cpp
 *
 * [531] Lonely Pixel I
 */

// @lc code=start
class Solution {
 public:
  int findLonelyPixel(vector<vector<char>>& A) {
    int m = A.size(), n = A[0].size();
    vector<int> rowb(m), colb(n);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (A[i][j] == 'B') rowb[i]++, colb[j]++;

    int res = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (A[i][j] == 'B' && rowb[i] == 1 && colb[j] == 1) res++;

    return res;
  }
};
// @lc code=end
