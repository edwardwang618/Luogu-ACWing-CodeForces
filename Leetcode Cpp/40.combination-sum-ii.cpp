/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int> &A, int target) {
    vector<vector<int>> res;
    sort(A.begin(), A.end(), greater<int>());

    vector<int> v;
    dfs(0, target, A, v, res);
    return res;
  }

  void dfs(int u, int target, vector<int> &A, vector<int> &v,
           vector<vector<int>> &res) {
    if (!target) res.push_back(v);

    for (int i = u; i < A.size(); i++) {
      if (i > u && A[i] == A[i - 1]) continue;

      if (target >= A[i]) {
        v.push_back(A[i]);
        dfs(i + 1, target - A[i], A, v, res);
        v.pop_back();
      }
    }
  }
};
// @lc code=end
