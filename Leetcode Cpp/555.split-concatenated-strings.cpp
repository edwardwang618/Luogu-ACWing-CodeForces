/*
 * @lc app=leetcode id=555 lang=cpp
 *
 * [555] Split Concatenated Strings
 */

// @lc code=start
class Solution {
public:
  string splitLoopedString(vector<string> &ss) {
    string s, res;
    for (auto &t : ss) {
      string r(t.rbegin(), t.rend());
      s += max(t, r);
    }

    for (int i = 0, st = 0; i < ss.size(); st += ss[i++].size()) {
      string b = s.substr(st + ss[i].size()) + s.substr(0, st);
      string p1 = ss[i], p2(p1.rbegin(), p1.rend());

      for (int j = 0; j < p1.size(); j++) {
        if (p1[j] >= res[0])
          res = max(res, p1.substr(j) + b + p1.substr(0, j));
        if (p2[j] >= res[0])
          res = max(res, p2.substr(j) + b + p2.substr(0, j));
      }
    }
    return res;
  }
};
// @lc code=end
