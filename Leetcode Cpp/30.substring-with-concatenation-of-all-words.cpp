/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
  using ull = unsigned long long;
  vector<int> findSubstring(string s, vector<string> &ws) {
    int n = s.size(), m = ws.size();
    s = " " + s;
    static constexpr ull P = 131;
    int len = ws[0].size();
    vector<ull> ha(n + 1), pow(n + 1);
    pow[0] = 1;
    for (int i = 1; i <= n; i++)
      ha[i] = ha[i - 1] * P + s[i], pow[i] = pow[i - 1] * P;
    auto get_ha = [&](int l, int r) {
      return ha[r] - ha[l - 1] * pow[r - l + 1];
    };
    unordered_map<ull, int> mp;
    for (auto &w : ws) {
      ull h = 0;
      for (char ch : w)
        h = h * P + ch;
      ++mp[h];
    }

    vector<int> res;
    for (int i = 1; i <= len; i++) {
      unordered_map<ull, int> cnt_mp;
      int cnt = 0;
      // ... j, j+1,j+len-1
      for (int j = i; j + len - 1 <= n; j += len) {
        ull h = get_ha(j, j + len - 1);
        if (++cnt_mp[h] <= mp[h])
          cnt++;
        int pl = j - m * len, pr = pl + len - 1;
        if (pl >= 1) {
          ull h = get_ha(pl, pr);
          if (cnt_mp[h]-- <= mp[h])
            cnt--;
        }
        if (cnt == m)
          res.push_back(pr);
      }
    }

    return res;
  }
};
// @lc code=end
