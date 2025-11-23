/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 */

// @lc code=start
class Solution {
 public:
  vector<int> xorQueries(vector<int>& A, vector<vector<int>>& qs) {
    vector<int> res;
    int pre[A.size() + 1];
    pre[0] = 0;
    for (int i = 0; i < A.size(); i++) pre[i + 1] = pre[i] ^ A[i];

    for (auto& q : qs) res.push_back(pre[q[1] + 1] ^ pre[q[0]]);
    return res;
  }
};
// @lc code=end
