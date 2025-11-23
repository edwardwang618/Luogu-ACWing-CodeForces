/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
 public:
  stack<int> stk, stk0;
  MyQueue() {}

  void push(int x) { stk.push(x); }

  int pop() {
    if (stk0.empty()) {
      while (stk.size()) {
        stk0.push(stk.top());
        stk.pop();
      }
    }
    int res = stk0.top();
    stk0.pop();
    return res;
  }

  int peek() {
    if (stk0.empty()) {
      while (stk.size()) {
        stk0.push(stk.top());
        stk.pop();
      }
    }
    return stk0.top();
  }

  bool empty() { return stk.empty() && stk0.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
