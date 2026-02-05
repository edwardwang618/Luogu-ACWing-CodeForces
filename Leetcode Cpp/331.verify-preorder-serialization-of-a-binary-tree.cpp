/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */

// @lc code=start
class Solution {
public:
  // bool isValidSerialization(string t) {
  //   istringstream ss(t);
  //   vector<string> v;
  //   for (string s; getline(ss, s, ',');)
  //     v.push_back(s);
  //   int idx = 0;
  //   auto dfs = [&](this auto &&dfs) -> bool {
  //     if (idx == v.size())
  //       return false;
  //     if (v[idx] == "#") {
  //       idx++;
  //       return true;
  //     }

  //     idx++;
  //     return dfs() && dfs();
  //   };
  //   return dfs() && idx == v.size();
  // }

  bool isValidSerialization(string t) {
    istringstream ss(t);
    vector<string> v;
    for (string s; getline(ss, s, ',');)
      v.push_back(s);
    stack<string> stk;
    for (string &s : v) {
      if (s == "#") {
        while (stk.size() && stk.top() == "#") {
          stk.pop();
          if (stk.empty()) return false;
          stk.pop();
        }
      }
      stk.push(s);
    }

    return stk.size() == 1 && stk.top() == "#";
  }
};
// @lc code=end
