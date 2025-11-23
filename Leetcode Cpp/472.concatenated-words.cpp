/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 */

// @lc code=start
class Solution {
 public:
  using UL = unsigned long;
  UL P = 131;

  vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
    vector<string> res;
    unordered_set<UL> st;
    for (auto &s : words) {
      UL ha = 0;
      for (char ch : s) ha = ha * P + ch;
      st.insert(ha);
    }

    for (auto &s : words)
      if (check(s, st)) res.push_back(s);

    return res;
  }

  bool check(string &s, unordered_set<UL> &st) {
    int n = s.size();
    vector<int> f(n + 1, -1);
    f[0] = 0;
    for (int i = 0; i <= n; i++) {
      if (f[i] == -1) continue;
      UL ha = 0;
      for (int j = i + 1; j <= n; j++) {
        ha = ha * P + s[j - 1];
        if (st.count(ha)) f[j] = max(f[i] + 1, f[j]);
        if (f[n] > 1) return true;
      }
    }

    return false;
  }
};
// @lc code=end
