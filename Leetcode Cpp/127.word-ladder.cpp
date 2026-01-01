/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
  int ladderLength(string &begin, string &end, vector<string> &v) {
    if (begin == end) return 1;
    unordered_set<string> ws(v.begin(), v.end());
    if (ws.find(end) == ws.end()) return 0;
    ws.insert(begin);
    queue<string> bq, eq;
    bq.push(begin), eq.push(end);
    unordered_set<string> bvis, evis;
    bvis.insert(begin), evis.insert(end);
    auto one_step = [&](auto &bq, auto &bvis, auto &evis) {
      for (int i = bq.size(); i; i--) {
        auto s = bq.front(); bq.pop();
        for (char &c : s) {
          char tmp = c;
          for (char d = 'a'; d <= 'z'; d++) {
            if (d == tmp) continue;
            c = d;
            if (!ws.count(s)) continue;
            if (evis.count(s)) return true;
            auto [_, ins] = bvis.insert(s);
            if (ins) bq.push(s);
          }
          c = tmp;
        }
      }
      return false;
    };
    int res = 1;
    while (bq.size() && eq.size()) {
      res++;
      if (bq.size() < eq.size()) {
        if (one_step(bq, bvis, evis)) return res;
      } else if (one_step(eq, evis, bvis)) return res;
    }
    return 0;
  }
};
// @lc code=end
