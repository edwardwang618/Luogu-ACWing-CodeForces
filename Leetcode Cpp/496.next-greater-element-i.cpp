/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &qs, vector<int> &a) {
    vector<int> res(qs.size(), -1);
    unordered_map<int, int> mp;
    for (int i = 0; i < qs.size(); i++) mp[qs[i]] = i;
    stack<int> stk;
    for (int x : a) {
      while (stk.size() && stk.top() < x) {
        int t = stk.top(); stk.pop();
        if (auto it = mp.find(t); it != mp.end()) res[it->second] = x;
      }
      stk.push(x);
    }
    return res;
  }
};
// @lc code=end
