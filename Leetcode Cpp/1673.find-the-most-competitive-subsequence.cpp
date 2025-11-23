/*
 * @lc app=leetcode id=1673 lang=cpp
 *
 * [1673] Find the Most Competitive Subsequence
 */

// @lc code=start
class Solution {
 public:
  vector<int> mostCompetitive(vector<int>& a, int k) {
    vector<int> res(k);
    int top = 0, n = a.size();
    k = n - k;
    for (int i = 0; i < n; i++) {
      while (top && res[top - 1] > a[i] && k) {
        top--;
        k--;
      }
      if (top < res.size()) res[top++] = a[i];
      else k--;
    }

    return res;
  }
};
// @lc code=end
