/*
 * @lc app=leetcode id=2364 lang=cpp
 *
 * [2364] Count Number of Bad Pairs
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  ll countBadPairs(vector<int>& a) {
    int n = a.size();
    ll res = (ll)n * (n - 1) / 2;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
      res -= mp[a[i] - i];
      mp[a[i] - i]++;
    }
    return res;
  }
};
// @lc code=end
