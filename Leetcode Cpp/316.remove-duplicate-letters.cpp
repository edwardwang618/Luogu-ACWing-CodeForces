/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
class Solution {
public:
  string removeDuplicateLetters(string &s) {
    int last[26];
    bool used[26] = {false};
    int n = s.size();
    for (int i = 0; i < n; i++)
      last[s[i] - 'a'] = i;
    string res;
    for (int i = 0; i < n; i++) {
      char ch = s[i];
      int idx = ch - 'a';
      if (used[idx])
        continue;
      while (res.size() && res.back() >= ch) {
        int idx = res.back() - 'a';
        if (last[idx] > i) {
          used[idx] = false;
          res.pop_back();
        } else
          break;
      }
      res += ch;
      used[idx] = true;
    }
    return res;
  }
};
// @lc code=end
