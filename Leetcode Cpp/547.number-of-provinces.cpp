/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
 public:
  vector<int> p;
  int findCircleNum(vector<vector<int>>& A) {
    int n = A.size(), cnt = n;
    p.resize(n);
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        if (!A[i][j]) continue;
        int pi = find(i), pj = find(j);
        if (pi != pj) {
          p[pi] = pj;
          cnt--;
        }
      }

    return cnt;
  }

  int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
  }
};
// @lc code=end
