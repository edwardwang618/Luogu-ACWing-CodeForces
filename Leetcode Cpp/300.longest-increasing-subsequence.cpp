/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
  int lengthOfLIS(vector<int> &a) {
    int n = a.size();
    vector<int> f;
    for (int i = 0; i < n; i++) {
      int x = a[i], m = f.size();
      int l = 0, r = m - 1;
      while (l < r) {
        int mid = l + r >> 1;
        if (f[mid] >= x) r = mid;
        else l = mid + 1;
      }
      if (l >= m || f[l] < x) f.push_back(x);
      else f[l] = x;
    }
    return f.size();
  }
};
// @lc code=end
