/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// @lc code=start
class Solution {
public:
  string predictPartyVictory(string ss) {
    int n = ss.size();
    queue<int> R, D;
    for (int i = 0; i < n; i++)
      if (ss[i] == 'R')
        R.push(i);
      else
        D.push(i);

    while (R.size() && D.size()) {
      int r = R.front();
      R.pop();
      int d = D.front();
      D.pop();
      if (r < d)
        R.push(r + n);
      else
        D.push(d + n);
    }
    return R.empty() ? "Dire" : "Radiant";
  }
};
// @lc code=end
