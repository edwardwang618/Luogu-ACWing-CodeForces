/*
 * @lc app=leetcode id=1044 lang=cpp
 *
 * [1044] Longest Duplicate Substring
 */

// @lc code=start
class Solution {
 public:
  using ull = unsigned long long;
  string longestDupSubstring(string& s) {
    static auto f = [&](int len, int& res_l) {
      int n = s.size();
      ull ha = 0, pow = 1;
      static constexpr ull P = 131;
      unordered_set<ull> st;
      st.reserve(n - len + 1);
      for (int i = 0; i < len; i++) ha = ha * P + s[i], pow *= P;
      st.insert(ha);
      for (int i = len; i < n; i++) {
        ha = ha * P + s[i];
        ha -= s[i - len] * pow;
        auto [_, ins] = st.insert(ha);
        if (!ins) {
          res_l = i - len + 1;
          return true;
        }
      }
      return false;
    };
    int l = 0, r = s.size() - 1;
    int res_l = 0;
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (f(mid, res_l)) l = mid;
      else r = mid - 1;
    }
    return s.substr(res_l, l);
  }
};
// @lc code=end
