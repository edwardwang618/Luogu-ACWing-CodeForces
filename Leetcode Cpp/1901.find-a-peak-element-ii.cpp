/*
 * @lc app=leetcode id=1901 lang=cpp
 *
 * [1901] Find a Peak Element II
 */

// @lc code=start
class Solution {
 public:
  vector<int> findPeakGrid(vector<vector<int>>& A) {
    vector<int> res;
    int m = A.size(), n = A[0].size();
    int l = 0, r = m - 1;
    int max_col = 0;
    while (l < r) {
      int mid = l + (r - l >> 1);
      for (int i = 0; i < n; i++)
        if (A[mid][i] > A[mid][max_col]) max_col = i;
      if ((!mid || A[mid][max_col] > A[mid - 1][max_col]) &&
          (mid == m - 1 || A[mid][max_col] > A[mid + 1][max_col]))
        return {mid, max_col};

      if (mid && A[mid][max_col] < A[mid - 1][max_col])
        r = mid;
      else
        l = mid + 1;
    }

    return {l, max_col};
  }
};
// @lc code=end
