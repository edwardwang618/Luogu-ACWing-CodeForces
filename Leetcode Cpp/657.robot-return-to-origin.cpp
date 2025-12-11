/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
class Solution {
public:
  bool judgeCircle(string moves) {
    int x = 0, y = 0;
    for (char ch : moves) {
      if (ch == 'U')
        x--;
      else if (ch == 'D')
        x++;
      else if (ch == 'L')
        y--;
      else
        y++;
    }
    return !x && !y;
  }
};
// @lc code=end
