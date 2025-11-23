/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
 public:
  int lengthOfLIS(vector<int>& a) {
    int n = a.size(), f[n];
    memset(f, 0, sizeof f);
    int idx = 0;
    for (int i = 0; i < a.size(); i++) {
      int l = 0, r = idx - 1, pos;
      if (l > r) pos = -1;
      else {
        while (l < r) {
          int mid = l + (r - l >> 1);
          if (f[mid] >= a[i]) r = mid;
          else l = mid + 1;
        }

        pos = f[l] >= a[i] ? l : -1;
      }

      ~pos ? f[pos] = a[i] : f[idx++] = a[i];
    }

    return idx;
  }
};
// @lc code=end
