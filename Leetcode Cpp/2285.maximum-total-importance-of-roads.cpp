/*
 * @lc app=leetcode id=2285 lang=cpp
 *
 * [2285] Maximum Total Importance of Roads
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  ll maximumImportance(int n, vector<vector<int>>& rs) {
    vector<int> cnt(n);
    for (auto& r : rs) cnt[r[0]]++, cnt[r[1]]++;
    sort(cnt.begin(), cnt.end());
    ll res = 0;
    for (int i = 0; i < n; i++) res += (ll)(i + 1) * cnt[i];
    return res;
  }
};
// @lc code=end
