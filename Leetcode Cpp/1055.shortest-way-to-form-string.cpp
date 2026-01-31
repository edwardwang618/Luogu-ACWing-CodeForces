/*
 * @lc app=leetcode id=1055 lang=cpp
 *
 * [1055] Shortest Way to Form String
 */

// @lc code=start
class Solution {
public:
  int shortestWay(string &s, string &t) {
    int n = s.size();
    vector<array<int, 26>> dfa(n + 1);
    for (int i = n - 1; i >= 0; i--) {
      dfa[i] = dfa[i + 1];
      dfa[i][s[i] - 'a'] = i + 1;
    }

    int res = 1, pos = 0;
    for (char ch : t) {
      int idx = ch - 'a';
      if (!dfa[0][idx])
        return -1;
      if (!dfa[pos][idx]) {
        res++;
        pos = 0;
      }
      pos = dfa[pos][idx];
    }
    return res;
  }
};
// @lc code=end
