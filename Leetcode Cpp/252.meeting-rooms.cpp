/*
 * @lc app=leetcode id=252 lang=cpp
 *
 * [252] Meeting Rooms
 */

// @lc code=start
class Solution {
public:
  bool canAttendMeetings(vector<vector<int>> &ins) {
    sort(ins.begin(), ins.end());
    int ed = INT_MIN;
    for (auto &i : ins) {
      if (ed > i[0]) return false;
      ed = i[1];
    }
    return true;
  }
};
// @lc code=end
