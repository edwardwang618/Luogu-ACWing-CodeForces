/*
 * @lc app=leetcode id=936 lang=cpp
 *
 * [936] Stamping The Sequence
 */

// @lc code=start
class Solution {
 public:
  vector<int> movesToStamp(string stamp, string s) {
    vector<int> res;
    bool can_do = true;
    while (can_do) {
      can_do = false;
      for (int i = 0; i + stamp.size() <= s.size(); i++)
        if (work(stamp, s, i)) {
          can_do = true;
          res.push_back(i);
        }
    }

    if (s != string(s.size(), '?')) return {};
    reverse(res.begin(), res.end());
    return res;
  }

  bool work(string& p, string& s, int i) {
    if (s.substr(i, p.size()) == string(p.size(), '?')) return false;
    for (int k = 0; k < p.size(); k++)
      if (s[i + k] != p[k] && s[i + k] != '?')
        return false;
    
    for (int k = 0; k < p.size(); k++)
      s[i + k] = '?';

    return true;
  }
};
// @lc code=end
