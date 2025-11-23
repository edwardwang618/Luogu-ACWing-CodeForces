/*
 * @lc app=leetcode id=2090 lang=cpp
 *
 * [2090] K Radius Subarray Averages
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  vector<int> getAverages(vector<int>& a, int k) {
    int n = a.size();
    vector<int> res(n, -1);
    vector<ll> p(n + 1);
    for (int i = 0; i < n; i++) p[i + 1] = p[i] + a[i];
    for (int i = k; i + k < n; i++) {
      int l = i - k, r = i + k;
      res[i] = (p[r + 1] - p[l]) / (2 * k + 1);
    }
    return res;
  }
};
// @lc code=end
