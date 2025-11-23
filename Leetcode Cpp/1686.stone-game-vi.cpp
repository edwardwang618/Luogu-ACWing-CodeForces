/*
 * @lc app=leetcode id=1686 lang=cpp
 *
 * [1686] Stone Game VI
 */

// @lc code=start
class Solution {
 public:
  int stoneGameVI(vector<int>& as, vector<int>& bs) {
    int n = as.size();
    vector<vector<int>> ps(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) ps[i][0] = as[i], ps[i][1] = bs[i];
    sort(ps.begin(), ps.end(),
         [](auto& p1, auto& p2) { return p1[0] + p1[1] > p2[0] + p2[1]; });

    int ascore = 0, bscore = 0;
    for (int i = 0; i < n; i++)
      i % 2 == 0 ? ascore += ps[i][0] : bscore += ps[i][1];

    return ascore == bscore ? 0 : ascore < bscore ? -1 : 1;
  }
};
// @lc code=end
