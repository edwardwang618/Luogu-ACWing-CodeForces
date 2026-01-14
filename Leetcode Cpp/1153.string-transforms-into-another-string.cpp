/*
 * @lc app=leetcode id=1153 lang=cpp
 *
 * [1153] String Transforms Into Another String
 */

// @lc code=start
class Solution {
public:
  bool canConvert(string &s1, string &s2) {
    if (s1 == s2)
      return true;
    int mp[26]{};
    for (int i = 0; i < s1.size(); i++) {
      int x = s1[i] - 'a', y = s2[i] - 'a';
      if (mp[x]) {
        if (mp[x] != y + 1)
          return false;
      } else
        mp[x] = y + 1;
    }

    return unordered_set<char>(s2.begin(), s2.end()).size() < 26;
  }
};
// @lc code=end
