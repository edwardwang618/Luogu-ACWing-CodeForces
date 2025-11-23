/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
 public:
  stack<int> stk, stk_min;
  MinStack() {}

  void push(int x) {
    stk.push(x);
    if (stk_min.empty() || x <= stk_min.top()) stk_min.push(x);
  }

  void pop() {
    if (stk.top() == stk_min.top()) stk_min.pop();
    stk.pop();
  }

  int top() { return stk.top(); }

  int getMin() { return stk_min.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
