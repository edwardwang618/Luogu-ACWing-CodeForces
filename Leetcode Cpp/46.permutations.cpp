/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
 public:
  // vector<vector<int>> permute(vector<int>& A) {
  //   vector<vector<int>> res;
  //   vector<int> v;
  //   int vis = 0;
  //   dfs(v, A, vis, res);
  //   return res;
  // }

  // void dfs(vector<int>& v, vector<int>& A, int& vis, vector<vector<int>>&
  // res) {
  //   if (v.size() == A.size()) {
  //     res.push_back(v);
  //     return;
  //   }

  //   for (int i = 0; i < A.size(); i++) {
  //     if (vis >> i & 1) continue;
  //     vis |= 1 << i;
  //     v.push_back(A[i]);
  //     dfs(v, A, vis, res);
  //     v.pop_back();
  //     vis -= 1 << i;
  //   }
  // }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    dfs(0, nums, res);
    return res;
  }

  void dfs(int u, vector<int>& v, vector<vector<int>>& res) {
    if (u == v.size()) {
      res.push_back(v);
      return;
    }

    for (int i = u; i < v.size(); i++) {
      swap(v[i], v[u]);
      dfs(u + 1, v, res);
      swap(v[i], v[u]);
    }
  }
};
// @lc code=end
