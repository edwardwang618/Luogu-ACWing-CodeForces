/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
  string decodeString(string &s) {
    string res;
    stack<string> s_stk;
    stack<int> rep_stk;
    for (int i = 0; i < s.size(); i++) {
      char ch = s[i];
      if (isdigit(ch)) {
        int j = i, x = 0;
        while (j < s.size() && isdigit(s[j]))
          x = x * 10 + s[j++] - '0';
        rep_stk.push(x);
        i = j - 1;
      } else if (isalpha(ch)) res += ch;
      else if (ch == '[') {
        s_stk.push(res);
        res.clear();
      } else {
        // ch = ]
        int rep = rep_stk.top(); rep_stk.pop();
        string tmp;
        tmp.reserve(rep * res.size());
        while (rep--) tmp += res;
        res = move(s_stk.top()); s_stk.pop();
        res += tmp;
      }
    }
    return res;
  }
};
// @lc code=end
