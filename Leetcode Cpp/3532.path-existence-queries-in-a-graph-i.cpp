/*
 * @lc app=leetcode id=3532 lang=cpp
 *
 * [3532] Path Existence Queries in a Graph I
 */

// @lc code=start
class Solution {
public:
  vector<bool> pathExistenceQueries(int n, vector<int> &a, int maxDiff,
                                    vector<vector<int>> &qs) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    for (int i = 1; i < n; i++)
      if (a[i] - a[i - 1] <= maxDiff) p[i] = p[i - 1];

    vector<bool> res;
    res.reserve(qs.size());
    for (auto &q : qs) res.push_back(p[q[0]] == p[q[1]]);
    return res;
  }
};
// @lc code=end
