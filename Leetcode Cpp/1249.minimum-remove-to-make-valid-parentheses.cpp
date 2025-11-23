/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
class Solution {
 public:
  // string minRemoveToMakeValid(string s) {
  //   int l = 0, r = 0;
  //   for (int i = 0; i < s.size(); i++) {
  //     if (s[i] != '(' && s[i] != ')') continue;
  //     s[i] == '(' ? l++ : r++;
  //     if (l < r) s[i] = ' ', r--;
  //   }

  //   int del = l - r;
  //   string res;
  //   for (int i = s.size() - 1; i >= 0; i--)
  //     if (s[i] != ' ') {
  //       if (s[i] == '(' && del > 0)
  //         del--;
  //       else
  //         res += s[i];
  //     }

  //   reverse(res.begin(), res.end());
  //   return res;
  // }

  string minRemoveToMakeValid(string s) {
    stack<int> stk;
    for (int i = 0, cnt = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        stk.push(i);
        cnt++;
      } else if (s[i] == ')') {
        if (!cnt)
          s[i] = '#';
        else {
          cnt--;
          stk.pop();
        }
      }
    }
    while (stk.size()) {
      s[stk.top()] = '#';
      stk.pop();
    }
    string res;
    for (char c : s)
      if (c != '#') res += c;
    return res;
  }
};
// @lc code=end
