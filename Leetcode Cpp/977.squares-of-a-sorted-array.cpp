/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& a) {
    vector<int> res(a.size());
    for (int i = 0, j = a.size() - 1, k = a.size() - 1; i <= j; k--) {
      if (abs(a[i]) > abs(a[j])) {
        res[k] = a[i] * a[i];
        i++;
      } else {
        res[k] = a[j] * a[j];
        j--;
      }
    }
    return res;
  }
};
// @lc code=end
