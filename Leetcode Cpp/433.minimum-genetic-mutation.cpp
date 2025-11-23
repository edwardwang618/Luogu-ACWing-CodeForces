/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution {
 public:
  int minMutation(string start, string end, vector<string>& bank) {
    string gs = "ACGT";
    unordered_set<string> st(bank.begin(), bank.end());
    if (!st.count(end)) return -1;
    if (start == end) return 0;
    queue<string> bq, eq;
    unordered_set<string> bvis, evis;
    bq.push(start);
    eq.push(end);
    bvis.insert(start);
    evis.insert(end);
    int res = 0;
    while (bq.size() && eq.size()) {
      res++;
      if (bq.size() <= eq.size()) {
        if (one_step(bq, bvis, evis, st, gs)) return res;
      } else {
        if (one_step(eq, evis, bvis, st, gs)) return res;
      }
    }

    return -1;
  }

  bool one_step(queue<string>& bq, unordered_set<string>& bvis,
                unordered_set<string>& evis, unordered_set<string>& st,
                string& gs) {
    for (int i = bq.size(); i; i--) {
      auto s = bq.front();
      bq.pop();
      for (int j = 0; j < s.size(); j++) {
        char old = s[j];
        for (char g : gs) {
          if (old == g) continue;
          s[j] = g;
          if (st.count(s) && !bvis.count(s)) {
            if (evis.count(s)) return true;
            bvis.insert(s);
            bq.push(s);
          }
        }
        s[j] = old;
      }
    }

    return false;
  }
};
// @lc code=end
