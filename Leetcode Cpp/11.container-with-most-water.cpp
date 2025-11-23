/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
 public:
  int maxArea(vector<int>& h) {
    int n = h.size();
    int res = 0;
    for (int i = 0, j = n - 1; i < j;) {
      res = max(res, min(h[i], h[j]) * (j - i));
      if (h[i] < h[j])
        i++;
      else if (h[i] > h[j])
        j--;
      else
        i++, j--;
    }
    return res;
  }
};
// @lc code=end
