/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
 public:
  void rotate(vector<int>& A, int k) {
    int n = A.size();
    k %= n;
    reverse(A.begin(), A.end());
    reverse(A.begin(), A.begin() + k);
    reverse(A.begin() + k, A.end());
  }
};
// @lc code=end
