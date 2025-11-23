/*
 * @lc app=leetcode id=2366 lang=cpp
 *
 * [2366] Minimum Replacements to Sort the Array
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  ll minimumReplacement(vector<int>& a) {
    int n = a.size();
    ll res = 0;
    for (int i = n - 2; i >= 0; i--)
      if (a[i] > a[i + 1]) {
        int k = (a[i] + a[i + 1] - 1) / a[i + 1];
        res += k - 1;
        a[i] /= k;
      }
    return res;
  }
};
// @lc code=end
