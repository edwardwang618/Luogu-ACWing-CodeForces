/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
class Solution {
 public:
  int maxChunksToSorted(vector<int>& a) {
    int n = a.size(), res = 0;
    for (int i = 0, max_i = 0; i < n; i++) {
      max_i = max(max_i, a[i]);
      if (i == max_i) res++;
    }

    return res;
  }
};
// @lc code=end
