/*
 * @lc app=leetcode id=1324 lang=cpp
 *
 * [1324] Print Words Vertically
 */

// @lc code=start
class Solution {
 public:
  vector<string> printVertically(string s) {
    vector<string> res;
    for (int i = 0, x = 0, y = 0; i < s.size(); i++) {
      if (s[i] == ' ') continue;
      x = 0;
      int j = i;
      while (j < s.size() && s[j] != ' ') {
        if (res.size() <= x) res.push_back("");
        while (res[x].size() < y) res[x] += ' ';
        res[x] += s[j++];
        x++;
      }

      y++;
      i = j;
    }

    return res;
  }
};
// @lc code=end
