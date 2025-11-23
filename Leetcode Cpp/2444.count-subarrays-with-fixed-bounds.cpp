/*
 * @lc app=leetcode id=2444 lang=cpp
 *
 * [2444] Count Subarrays With Fixed Bounds
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  ll countSubarrays(vector<int>& a, int minK, int maxK) {
    ll res = 0;
    int last_min = -1, last_max = -1, l_bound = -1;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] < minK || a[i] > maxK) {
        l_bound = i;
        last_min = last_max = -1;
      } else {
        if (a[i] == minK) last_min = i;
        if (a[i] == maxK) last_max = i;
        if (min(last_min, last_max) > l_bound)
          res += min(last_min, last_max) - l_bound;
      }
    }
    return res;
  }
};
// @lc code=end
