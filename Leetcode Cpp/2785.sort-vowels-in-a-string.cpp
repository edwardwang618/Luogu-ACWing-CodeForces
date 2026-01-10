/*
 * @lc app=leetcode id=2785 lang=cpp
 *
 * [2785] Sort Vowels in a String
 */

// @lc code=start
class Solution {
public:
  string sortVowels(string &s) {
    map<char, int> mp;
    auto check = [](char ch) {
      ch = tolower(ch);
      return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    };
    for (char ch : s) if (check(ch)) mp[ch]++;
    auto it = mp.begin();
    for (char &ch : s) {
      if (!check(ch)) continue;
      if (!it->second) ++it;
      ch = it->first;
      it->second--;
    }
    return s;
  }
};
// @lc code=end
