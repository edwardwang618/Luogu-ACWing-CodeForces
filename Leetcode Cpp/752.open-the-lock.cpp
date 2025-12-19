/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
class Solution {
 public:
  int openLock(vector<string>& deadends, string& end) {
    string begin = "0000";
    if (begin == end) return 0;
    unordered_set<string> dead(deadends.begin(), deadends.end()), vis1, vis2;
    if (dead.count(begin) || dead.count(end)) return -1;
    queue<string> q1, q2;
    q1.push(begin), q2.push(end);
    vis1.insert(begin), vis2.insert(end);

    int res = 0;
    while (q1.size() && q2.size()) {
      res++;
      if (q1.size() <= q2.size()) {
        if (one_step(q1, vis1, vis2, dead)) return res;
      } else if (one_step(q2, vis2, vis1, dead)) return res;
    }

    return -1;
  }

  bool one_step(queue<string>& q, unordered_set<string>& vis1,
                unordered_set<string>& vis2, unordered_set<string>& dead) {
    for (int i = q.size(); i; i--) {
      auto s = q.front(); q.pop();
      for (int j = 0; j < 4; j++) {
        char ch = s[j];
        for (int dx : {-1, 1}) {
          s[j] = (ch - '0' + dx + 10) % 10 + '0';
          if (vis2.count(s)) return true;
          if (!vis1.count(s) && !dead.count(s)) {
            vis1.insert(s);
            q.push(s);
          }
        }

        s[j] = ch;
      }
    }

    return false;
  }
};
// @lc code=end
