/*
 * @lc app=leetcode id=2354 lang=cpp
 *
 * [2354] Number of Excellent Pairs
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  ll countExcellentPairs(vector<int>& a, int k) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    auto f = [](int x) {
#define lowbit(x) (x) & (-x)
      int cnt = 0;
      while (x) x -= lowbit(x), cnt++;
      return cnt;
    };

    vector<int> cnt(31, 0);
    for (int x : a) cnt[f(x)]++;

    ll res = 0;
    for (int i = 0; i < 31; i++)
      for (int j = max(0, k - i); j < 31; j++) res += (ll)cnt[i] * cnt[j];
    return res;
  }
};
// @lc code=end
