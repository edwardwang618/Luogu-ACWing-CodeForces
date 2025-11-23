/*
 * @lc app=leetcode id=1381 lang=cpp
 *
 * [1381] Design a Stack With Increment Operation
 */

// @lc code=start
class CustomStack {
 public:
  vector<int> stk, add;
  int cap;
  CustomStack(int maxSize) { cap = maxSize; }

  void push(int x) {
    if (stk.size() == cap) return;
    stk.push_back(x);
    add.push_back(0);
  }

  int pop() {
    if (stk.empty()) return -1;
    int n = stk.size(), res = stk[n - 1] + add[n - 1];
    if (n >= 2) add[n - 2] += add[n - 1];
    stk.pop_back();
    add.pop_back();
    return res;
  }

  void increment(int k, int val) {
    if (stk.empty()) return;
    k = min(k, (int)stk.size());
    add[k - 1] += val;
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// @lc code=end
