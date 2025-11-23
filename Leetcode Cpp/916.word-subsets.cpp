/*
 * @lc app=leetcode id=916 lang=cpp
 *
 * [916] Word Subsets
 */

// @lc code=start
class Solution {
 public:
  vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
    int cnt[26] = {0};
    for (string& s : w2) {
      int cnt_s[26] = {0};
      for (char ch : s) cnt_s[ch - 'a']++;
      for (int i = 0; i < 26; i++) cnt[i] = max(cnt[i], cnt_s[i]);
    }

    vector<string> res;
    for (auto& s : w1) {
      int cnt_s[26] = {0};
      for (char ch : s) cnt_s[ch - 'a']++;
      bool valid = true;
      for (int i = 0; i < 26; i++)
        if (cnt[i] > cnt_s[i]) {
          valid = false;
          break;
        }
      if (valid) res.push_back(s);
    }
    return res;
  }
};
// @lc code=end
