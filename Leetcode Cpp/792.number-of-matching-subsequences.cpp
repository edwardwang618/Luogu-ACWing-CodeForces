/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 */

// @lc code=start
class Solution {
 public:
  int numMatchingSubseq(string s, vector<string>& ws) {
    int n = s.size();
    s = " " + s;
    int dfa[n + 1][26];
    memset(dfa, 0, sizeof dfa);
    for (int i = n - 1; i >= 0; i--) {
      for (int k = 0; k < 26; k++) dfa[i][k] = dfa[i + 1][k];
      dfa[i][s[i + 1] - 'a'] = i + 1;
    }

    auto check = [&](string& s) {
      for (int i = 0, p = 0; i < s.size(); i++) {
        if (!dfa[p][s[i] - 'a']) return false;
        p = dfa[p][s[i] - 'a'];
      }

      return true;
    };

    int res = 0;
    for (auto& w : ws)
      if (check(w)) res++;
    return res;
  }
};
// @lc code=end
