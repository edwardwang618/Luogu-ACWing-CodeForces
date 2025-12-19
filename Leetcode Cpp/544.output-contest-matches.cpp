/*
 * @lc app=leetcode id=544 lang=cpp
 *
 * [544] Output Contest Matches
 */

// @lc code=start
class Solution {
public:
  string findContestMatch(int n) {
    vector<string> cur;
    cur.reserve(n);
    for (int i = 1; i <= n; i++) cur.push_back(to_string(i));

    while (cur.size() > 1) {
      vector<string> ne;
      ne.reserve(cur.size() / 2);
      for (int i = 0, j = cur.size() - 1; i < j; i++, j--)
        ne.push_back("(" + cur[i] + "," + cur[j] + ")");
      cur = move(ne);
    }
    return cur[0];
  }
};
// @lc code=end
