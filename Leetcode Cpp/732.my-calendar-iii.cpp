/*
 * @lc app=leetcode id=732 lang=cpp
 *
 * [732] My Calendar III
 */

// @lc code=start
class MyCalendarThree {
public:
  map<int, int> mp;
  MyCalendarThree() {}

  int book(int st, int ed) {
    ++mp[st];
    --mp[ed];

    int res = 0, sum = 0;
    for (auto &[_, c] : mp) {
      sum += c;
      res = max(res, sum);
    }
    return res;
  }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
// @lc code=end
