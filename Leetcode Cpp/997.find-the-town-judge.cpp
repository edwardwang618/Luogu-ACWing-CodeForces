/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution {
public:
  int findJudge(int n, vector<vector<int>> &tt) {
    vector<int> in(n + 1), out(n + 1);
    for (auto &v : tt) {
      in[v[1]]++; 
      out[v[0]]++;
    }
    for (int i = 1; i <= n; i++)
      if (in[i] == n - 1 && !out[i]) return i;
    return -1;
  }
};
// @lc code=end
