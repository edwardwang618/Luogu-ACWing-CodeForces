/*
 * @lc app=leetcode id=1299 lang=cpp
 *
 * [1299] Replace Elements with Greatest Element on Right Side
 */

// @lc code=start
class Solution {
 public:
  vector<int> replaceElements(vector<int>& A) {
    vector<int> res(A.size());
    for (int i = A.size() - 1, max_v = -1; i >= 0; i--) {
      res[i] = max_v;
      max_v = max(max_v, A[i]);
    }

    return res;
  }
};
// @lc code=end
