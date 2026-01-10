/*
 * @lc app=leetcode id=2062 lang=cpp
 *
 * [2062] Count Vowel Substrings of a String
 */

// @lc code=start
class Solution {
public:
  int countVowelSubstrings(string &s) {
    auto isVowel = [](char c) {
      return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };

    auto f = [&](int cnt) {
      int res = 0;
      unordered_map<char, int> mp;
      for (int i = 0, j = 0; i < s.size(); i++) {
        if (!isVowel(s[i])) {
          j = i + 1;
          mp.clear();
          continue;
        }

        mp[s[i]]++;
        while (mp.size() > cnt) {
          auto it = mp.find(s[j]);
          if (it->second == 1) mp.erase(it);
          else it->second--;
          j++;
        }

        res += i - j + 1;
      }
      return res;
    };

    return f(5) - f(4);
  }
};
// @lc code=end
