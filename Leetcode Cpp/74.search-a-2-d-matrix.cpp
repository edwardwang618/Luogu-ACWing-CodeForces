/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& A, int t) {
    int n = A[0].size();
    int l = 0, r = (int)A.size() * n - 1;
    if (l > r) return false;
    while (l < r) {
      int mid = l + (r - l >> 1);
      int x = mid / n, y = mid % n;
      if (A[x][y] >= t) r = mid;
      else l = mid + 1;
    }

    return A[l / n][l % n] == t;
  }
};
// @lc code=end
