/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
class MyCalendar {
public:
  using PII = pair<int, int>;
  set<PII> cal;
  MyCalendar() {}

  bool book(int st, int ed) {
    auto it = cal.lower_bound({st, ed - 1});
    if (it != cal.end() && it->first < ed) return false;
    if (it != cal.begin()) {
      it = prev(it);
      if (it->second >= st) return false;
    }
    cal.emplace(st, ed - 1);
    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
// @lc code=end
