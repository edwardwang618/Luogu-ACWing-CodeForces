/*
 * @lc app=leetcode id=716 lang=cpp
 *
 * [716] Max Stack
 */

// @lc code=start
class MaxStack {
  using It = list<int>::iterator;
  // front == top
  list<int> stk;
  // value->iterators
  map<int, vector<It>> mp;

public:
  MaxStack() {}

  void push(int x) {
    stk.push_front(x);
    mp[x].push_back(stk.begin());
  }

  int pop() {
    int x = stk.front(); stk.pop_front();
    auto it = mp.find(x);
    if (it->second.size() == 1) mp.erase(it);
    else it->second.pop_back();
    return x;
  }

  int top() { return stk.front(); }

  int peekMax() { return mp.rbegin()->first; }

  int popMax() {
    auto it = prev(mp.end());
    int res = it->first;
    stk.erase(it->second.back());
    if (it->second.size() == 1) mp.erase(it);
    else it->second.pop_back();
    return res;
  }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
// @lc code=end
