/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
 public:
  int firstMissingPositive(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) 
      while (1 <= a[i] && a[i] <= n && a[a[i] - 1] != a[i]) 
        swap(a[i], a[a[i] - 1]);
    for (int i = 0; i < n; i++)
      if (a[i] != i + 1) return i + 1;
    return n + 1;
  }
};
// @lc code=end
