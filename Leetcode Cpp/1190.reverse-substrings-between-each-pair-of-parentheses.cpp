/*
 * @lc app=leetcode id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 */

// @lc code=start
class Solution {
 public:
  string reverseParentheses(string s) {
    stack<int> stk;
    unordered_map<int, int> mp;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') stk.push(i);
      else if (s[i] == ')') {
        mp[i] = stk.top();
        mp[stk.top()] = i;
        stk.pop();
      }
    }

    string res;
    for (int i = 0, step = 1; i < s.size(); i += step) {
      if (s[i] == '(' || s[i] == ')') {
        i = mp[i];
        step *= -1;
      } else res += s[i];
    }

    return res;
  }
};
// @lc code=end
