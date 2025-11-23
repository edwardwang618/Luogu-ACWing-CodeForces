/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 */

// @lc code=start
class Solution {
 public:
  string countOfAtoms(string s) {
    stack<unordered_map<string, int>> stk;
    stk.push({{}});
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        stk.push({{}});
      else if (s[i] == ')') {
        int j = ++i;
        while (j < s.size() && isdigit(s[j])) j++;
        int cnt = j > i ? stoi(s.substr(i, j - i)) : 1;
        auto mp = stk.top();
        stk.pop();
        for (auto &[k, v] : mp) stk.top()[k] += cnt * v;
        i = j - 1;
      } else {
        int j = i + 1;
        while (j < s.size() && islower(s[j])) j++;
        string elem = s.substr(i, j - i);
        i = j;
        while (j < s.size() && isdigit(s[j])) j++;
        int cnt = j > i ? stoi(s.substr(i, j - i)) : 1;
        stk.top()[elem] += cnt;
        i = j - 1;
      }
    }
    string res;
    assert(stk.size() == 1);
    map<string, int> mp(stk.top().begin(), stk.top().end());
    for (auto &[k, v] : mp) {
      res += k;
      if (v > 1) res += to_string(v);
    }

    return res;
  }
};
// @lc code=end
