/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// @lc code=start
class Solution {
 public:
  string getHint(string s, string g) {
    unordered_map<char, int> mp;
    for (char ch : s) mp[ch]++;
    int tot = 0;
    for (char ch : g)
      if (mp[ch]) {
        tot++;
        mp[ch]--;
      }

    int bulls = 0;
    for (int i = 0; i < s.size(); i++)
      if (s[i] == g[i]) bulls++;

    return to_string(bulls) + "A" + to_string(tot - bulls) + "B";
  }
};
// @lc code=end
