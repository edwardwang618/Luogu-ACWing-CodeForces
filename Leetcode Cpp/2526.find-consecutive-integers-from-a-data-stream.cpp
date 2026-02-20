/*
 * @lc app=leetcode id=2526 lang=cpp
 *
 * [2526] Find Consecutive Integers from a Data Stream
 */

// @lc code=start
class DataStream {
  int cnt;
  int x, k;

public:
  DataStream(int x, int k) : cnt(0), x(x), k(k) {}

  bool consec(int y) {
    cnt = y == x ? cnt + 1 : 0;
    return cnt >= k;
  }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
// @lc code=end
