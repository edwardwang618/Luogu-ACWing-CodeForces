/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& A) {
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    vector<int> v;
    int vis = 0;
    dfs(v, res, vis, A);
    return res;
  }

  void dfs(vector<int>& v, vector<vector<int>>& res, int& vis, vector<int>& A) {
    if (v.size() == A.size()) {
      res.push_back(v);
      return;
    }

    for (int i = 0; i < A.size(); i++) {
      if (vis >> i & 1) continue;
      if (i && A[i] == A[i - 1] && !(vis >> i - 1 & 1)) continue;
      v.push_back(A[i]);
      vis |= 1 << i;
      dfs(v, res, vis, A);
      vis -= 1 << i;
      v.pop_back();
    }
  }
};
// @lc code=end
