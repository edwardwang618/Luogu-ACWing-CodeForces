/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& a) {
    int i = 0;
    for (int j = 0; j < a.size(); j++)
      if (!i || a[j] != a[i - 1]) a[i++] = a[j];

    return i;
  }
};
// @lc code=end
