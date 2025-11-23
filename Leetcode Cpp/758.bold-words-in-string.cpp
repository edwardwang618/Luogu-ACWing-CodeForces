/*
 * @lc app=leetcode id=758 lang=cpp
 *
 * [758] Bold Words in String
 */

// @lc code=start
class Solution {
 public:
  using UL = unsigned long;
  string boldWords(vector<string>& ws, string s) {
    UL P = 131;
    int n = s.size();
    vector<UL> ha(n + 1), pow(n + 1);
    pow[0] = 1;
    for (int i = 0; i < n; i++) {
      ha[i + 1] = ha[i] * P + s[i];
      pow[i + 1] = pow[i] * P;
    }

    int M = 1, m = 10;
    unordered_set<UL> st;
    for (auto& w : ws) {
      M = max(M, (int)w.size());
      m = min(m, (int)w.size());
      UL h = 0;
      for (char ch : w) h = h * P + ch;
      st.insert(h);
    }

    vector<bool> mark(s.size());
    for (int i = m - 1; i < n; i++)
      for (int j = i - M + 1; j <= i - m + 1; j++) {
        if (j < 0) continue;
        UL h = ha[i + 1] - ha[j] * pow[i - j + 1];
        if (st.count(h)) {
          for (int k = j; k <= i; k++) mark[k] = true;
          break;
        }
      }

    string res;
    for (int i = 0; i < n; i++)
      if (!mark[i]) res += s[i];
      else {
        res += "<b>";
        while (i < n && mark[i]) res += s[i++];
        res += "</b>";
        i--;
      }

    return res;
  }
};
// @lc code=end
