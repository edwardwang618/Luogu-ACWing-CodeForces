/*
 * @lc app=leetcode id=636 lang=cpp
 *
 * [636] Exclusive Time of Functions
 */

// @lc code=start
class Solution {
 public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> res(n);
    stack<int> stk;
    int last = 0;
    for (auto& log : logs) {
      int pos1 = log.find(":");
      int pos2 = log.find(":", pos1 + 1);
      int id = stoi(log.substr(0, pos1));
      auto op = log.substr(pos1 + 1, pos2 - pos1 - 1);
      int time = stoi(log.substr(pos2 + 1));

      if (op == "start") {
        if (!stk.empty()) res[stk.top()] += time - last;
        stk.push(id);
        last = time;
      } else {
        res[stk.top()] += time - last + 1;
        stk.pop();
        last = time + 1;
      }
    }
    return res;
  }
};
// @lc code=end
