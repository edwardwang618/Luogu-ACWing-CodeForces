/*
 * @lc app=leetcode id=1044 lang=cpp
 *
 * [1044] Longest Duplicate Substring
 */

// @lc code=start
class Solution {
 public:
  using UL = unsigned long;
  string longestDupSubstring(string s) {
    int n = s.size();
    int ss = 0, sl = 0;
    auto check = [&](int len) {
      UL ha = 0, P = 131, pow = 1;
      for (int i = 0; i < len; i++) {
        ha = ha * P + s[i];
        pow = pow * P;
      }

      unordered_set<UL> st{ha};
      for (int i = len; i < n; i++) {
        ha = ha * P + s[i];
        ha -= pow * s[i - len];
        if (st.count(ha)) {
          ss = i - len + 1, sl = len;
          return true;
        }
        st.insert(ha);
      }

      return false;
    };

    int l = 0, r = n - 1;
    while (l < r) {
      int mid = l + (r - l + 1 >> 1);
      if (check(mid)) l = mid;
      else r = mid - 1;
    }

    return s.substr(ss, sl);
  }
};
// @lc code=end
