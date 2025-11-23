/*
 * @lc app=leetcode id=1626 lang=cpp
 *
 * [1626] Best Team With No Conflicts
 */

// @lc code=start
class Solution {
 public:
  int bestTeamScore(vector<int>& ss, vector<int>& as) {
    int n = ss.size();
    vector<int> ids(n);
    for (int i = 0; i < n; i++) ids[i] = i;
    sort(ids.begin(), ids.end(), [&](int i, int j) {
      return as[i] != as[j] ? as[i] < as[j] : ss[i] < ss[j];
    });
    vector<int> f(n, 0);
    int res = f[0] = ss[ids[0]];
    for (int i = 1; i < n; i++) {
      int k1 = ids[i];
      f[i] = ss[k1];
      for (int j = 0; j < i; j++) {
        int k2 = ids[j];
        if (ss[k2] <= ss[k1]) f[i] = max(f[i], ss[k1] + f[j]);
      }

      res = max(res, f[i]);
    }

    return res;
  }
};
// @lc code=end
