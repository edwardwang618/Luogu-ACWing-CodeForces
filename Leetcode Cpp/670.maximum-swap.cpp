/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

// @lc code=start
class Solution {
 public:
  int maximumSwap(int num) {
    string s = to_string(num);
    int mp[10];
    memset(mp, -1, sizeof mp);
    for (int i = 0; i < s.size(); i++) mp[s[i] - '0'] = i;
    for (int i = 0; i < s.size(); i++) {
      int x = s[i] - '0';
      for (int j = 9; j > x; j--)
        if (mp[j] > i) {
          swap(s[i], s[mp[j]]);
          return stoi(s);
        }
    }
    return num;
  }
};
// @lc code=end
