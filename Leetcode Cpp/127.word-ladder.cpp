/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
 public:
  int ladderLength(string begin, string end, vector<string>& words) {
    unordered_set<string> ws(words.begin(), words.end());
    if (!ws.count(end)) return 0;
    ws.insert(begin);
    unordered_set<string> bvis, evis;
    bvis.insert(begin);
    evis.insert(end);
    queue<string> bq, eq;
    bq.push(begin);
    eq.push(end);
    auto one_step = [&](queue<string>& bq, unordered_set<string>& bvis,
                        unordered_set<string>& evis) {
      for (int i = bq.size(); i; i--) {
        auto t = bq.front();
        bq.pop();
        auto s = t;
        for (int j = 0; j < t.size(); j++) {
          for (char ch = 'a'; ch <= 'z'; ch++) {
            if (ch == t[j]) continue;
            s[j] = ch;
            if (ws.count(s) && !bvis.count(s)) {
              if (evis.count(s)) return true;
              bvis.insert(s);
              bq.push(s);
            }
          }
          s[j] = t[j];
        }
      }
      return false;
    };
    int res = 0;
    while (bq.size() && eq.size()) {
      res++;
      if (bq.size() <= eq.size()) {
        if (one_step(bq, bvis, evis)) return res + 1;
      } else if (one_step(eq, evis, bvis))
        return res + 1;
    }

    return 0;
  }
};
// @lc code=end
