/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

// @lc code=start
class FreqStack {
public:
  unordered_map<int, int> freq;
  unordered_map<int, stack<int>> mp;
  int maxf;

  FreqStack() : maxf(0) {}

  void push(int x) {
    int f = ++freq[x];
    mp[f].push(x);
    if (f > maxf)
      maxf = f;
  }

  int pop() {
    auto &stk = mp[maxf];
    int res = stk.top();
    if (!--freq[res])
      freq.erase(res);
    if (stk.size() == 1)
      mp.erase(maxf--);
    else
      stk.pop();
    return res;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end
