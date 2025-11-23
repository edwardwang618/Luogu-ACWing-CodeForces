/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
 public:
  void sortColors(vector<int>& A) {
    for (int i = 0, j = 0, k = (int)A.size() - 1; j <= k;) {
      if (!A[j]) swap(A[i++], A[j++]);
      else if (A[j] == 2) swap(A[k--], A[j]);
      else j++;
    }
  }
};
// @lc code=end
