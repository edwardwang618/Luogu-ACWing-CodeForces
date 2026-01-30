/*
 * @lc app=leetcode id=2924 lang=cpp
 *
 * [2924] Find Champion II
 */

// @lc code=start
class Solution {
public:
  int findChampion(int n, vector<vector<int>> &es) {
    vector<int> ind(n);
    for (auto &e : es) ind[e[1]]++;
    int res, cnt = 0;
    for (int i = 0; i < n; i++)
      if (!ind[i]) {
        if (cnt == 1) return -1;
        cnt++;
        res = i;
      }
    return res;
  }
};
// @lc code=end
