/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
class Solution {
public:
  int maxVowels(string &s, int k) {
    auto is_vowel = [](char ch) {
      return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    };

    int cnt = 0, res = 0;
    for (int i = 0; i < s.size(); i++) {
      char ch = s[i];
      if (is_vowel(ch)) cnt++;
      if (i >= k && is_vowel(s[i - k])) cnt--;
      res = max(res, cnt);
    }
    return res;
  }
};
// @lc code=end
