/*
 * @lc app=leetcode id=3347 lang=cpp
 *
 * [3347] Maximum Frequency of an Element After Performing Operations II
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  int maxFrequency(vector<int>& a, int d, int ops) {
    vector<ll> b(a.begin(), a.end());
    if (d)
      for (int x : a) {
        b.push_back(x + d);
        b.push_back(x - d);
      }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    unordered_map<int, int> mp;
    int m = b.size();
    for (int i = 0; i < m; i++) mp[b[i]] = i;
    int cnt[m], s[m + 1];
    memset(cnt, 0, sizeof cnt);
    memset(s, 0, sizeof s);
    for (int x : a) cnt[mp[x]]++;
    for (int i = 1; i <= m; i++) s[i] = s[i - 1] + cnt[i - 1];
    int res = 1;
    for (int i = 0; i < m; i++) {
      int l = lower_bound(b.begin(), b.end(), b[i] - d) - b.begin(),
          r = upper_bound(b.begin(), b.end(), b[i] + d) - b.begin();
      res = max(res, min(s[r] - s[l] - cnt[i], ops) + cnt[i]);
    }

    return res;
  }
};
// @lc code=end
