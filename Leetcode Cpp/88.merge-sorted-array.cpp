/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int idx = nums1.size() - 1;
    for (int i = m - 1, j = n - 1; i >= 0 || j >= 0;) {
      if (j == -1) {
        while (i >= 0) nums1[idx--] = nums1[i--];
        break;
      }
      if (i == -1) {
        while (j >= 0) nums1[idx--] = nums2[j--];
        break;
      }

      if (nums1[i] >= nums2[j])
        nums1[idx--] = nums1[i--];
      else
        nums1[idx--] = nums2[j--];
    }
  }
};
// @lc code=end
