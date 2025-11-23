/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution {
 public:
  int compareVersion(string s1, string s2) {
    for (int i = 0, j = 0; i < s1.size() || j < s2.size(); ) {
      int x = i, y = j;
      while (x < s1.size() && s1[x] != '.') x++;
      while (y < s2.size() && s2[y] != '.') y++;
      int a = x == i ? 0 : stoi(s1.substr(i, x - i));
      int b = y == j ? 0 : stoi(s2.substr(j, y - j));
      if (a < b) return -1;
      if (a > b) return 1;
      i = x + 1, j = y + 1;
    }

    return 0;
  }
};
// @lc code=end
