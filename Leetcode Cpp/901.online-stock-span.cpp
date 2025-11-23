/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner {
 public:
  using PII = pair<int, int>;
  stack<PII> stk;
  int day;
  StockSpanner() {
    stk.push({-1, 2e9});
    day = 0;
  }

  int next(int x) {
    while (stk.size() && stk.top().second <= x) stk.pop();
    int res = day - stk.top().first;
    stk.push({day++, x});
    return res;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
