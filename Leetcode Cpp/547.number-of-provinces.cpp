/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:
  int findCircleNum(vector<vector<int>> &a) {
    int n = a.size(), cnt = n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return p[x] != x ? p[x] = find(p[x]) : x;
    };
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        if (!a[i][j])
          continue;
        int pi = find(i), pj = find(j);
        if (pi != pj) {
          p[pi] = pj;
          cnt--;
        }
      }

    return cnt;
  }
};
// @lc code=end
