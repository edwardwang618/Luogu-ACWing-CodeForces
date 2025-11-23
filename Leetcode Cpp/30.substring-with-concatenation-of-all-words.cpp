/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
 public:
  using ull = unsigned long long;
  vector<int> findSubstring(string s, vector<string>& ws) {
    int n = s.size(), m = ws.size(), len = ws[0].size();
    vector<ull> ha(n + 1), pow(n + 1);
    pow[0] = 1;
    constexpr ull P = 131;
    for (int i = 1; i <= n; i++)
      ha[i] = ha[i - 1] * P + s[i - 1], pow[i] = pow[i - 1] * P;
    auto hash_s = [&](int l, int r) {
      return ha[r + 1] - ha[l] * pow[r - l + 1];
    };
    unordered_map<ull, int> mp;
    for (int k = 0; k < ws.size(); k++) {
      auto& w = ws[k];
      ull ha = 0;
      for (int i = 0; i < w.size(); i++) ha = ha * P + w[i];
      ++mp[ha];
    }
    vector<int> res;
    for (int st = 0; st < len; st++) {
      unordered_map<ull, int> cnt_mp;
      int cnt = 0;
      for (int i = st; i + len - 1 < n; i += len) {
        if (i - m * len >= 0) {
          auto h = hash_s(i - m * len, i - (m - 1) * len - 1);
          if (cnt_mp[h]-- <= mp[h]) cnt--;
        }
        auto h = hash_s(i, i + len - 1);
        if (++cnt_mp[h] <= mp[h]) cnt++;
        if (cnt == m) res.push_back(i - (m - 1) * len);
      }
    }
    return res;
  }
};
// @lc code=end
