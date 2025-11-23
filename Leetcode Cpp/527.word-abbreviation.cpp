/*
 * @lc app=leetcode id=527 lang=cpp
 *
 * [527] Word Abbreviation
 */

// @lc code=start
class Solution {
 public:
  vector<string> wordsAbbreviation(vector<string>& ws) {
    int n = ws.size();
    vector<string> res(n);
    unordered_map<string, int> mp;
    int pre[n];
    memset(pre, 0, sizeof pre);
    auto abbr = [&](string& s, int i) {
      if (i >= s.size() - 2) return s;
      return s.substr(0, i) + to_string(s.size() - i - 1) + s.back();
    };
    for (int i = 0; i < n; i++) {
      pre[i] = 1;
      res[i] = abbr(ws[i], pre[i]);
      mp[res[i]]++;
    }

    bool unique = false;
    while (!unique) {
      unique = true;
      for (int i = 0; i < n; i++)
        if (mp[res[i]] > 1) {
          pre[i]++;
          res[i] = abbr(ws[i], pre[i]);
          mp[res[i]]++;
          unique = false;
        }
    }

    return res;
  }
};
// @lc code=end
