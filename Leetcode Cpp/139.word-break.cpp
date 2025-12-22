/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
 public:
  using ull = unsigned long long;
  bool wordBreak(string s, vector<string>& ws) {
    const ull P = 131;
    int n = s.size();
    vector<ull> pow(n + 1), hs(n + 1);
    pow[0] = 1;
    for (int i = 0; i < n; i++)
      pow[i + 1] = pow[i] * P, hs[i + 1] = hs[i] * P + s[i];
    auto hash = [&](int l, int r) {
      return hs[r + 1] - hs[l] * pow[r - l + 1];
    };

    int min_len = 2e9, max_len = 0;
    unordered_set<ull> st;
    st.reserve(ws.size());
    for (auto& s : ws) {
      int n = s.size();
      min_len = min(min_len, n);
      max_len = max(max_len, n);
      ull ha = 0;
      for (char ch : s) ha = ha * P + ch;
      st.insert(ha);
    }

    bool f[n];
    memset(f, 0, sizeof f);
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= i; j++)
        if (i - j + 1 >= min_len && i - j + 1 <= max_len &&
            st.count(hash(j, i))) {
          if (!j) f[i] = true;
          else f[i] = f[j - 1];

          if (f[i]) break;
        }

    return f[n - 1];
  }
};
// @lc code=end
