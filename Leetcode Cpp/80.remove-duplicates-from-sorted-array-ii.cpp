/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& A) {
    int j = 0;
    for (int i = 0; i < A.size(); i++) {
      if (j < 2 || A[i] > A[j - 1] || A[i] > A[j - 2]) A[j++] = A[i];
    }

    return j;
  }
};
// @lc code=end
