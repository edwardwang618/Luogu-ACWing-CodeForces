/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */

// @lc code=start
class Solution {
 public:
  bool canReach(vector<int>& arr, int start) {
    return dfs(start, arr);
  }

  bool dfs(int x, vector<int>& A) {
    if (!A[x]) return true;
    if (A[x] == -1) return false;
    int dx = A[x];
    A[x] = -1;
    if (x - dx >= 0 && dfs(x - dx, A)) return true;
    if (x + dx < A.size() && dfs(x + dx, A)) return true;
    return false;
  }
};
// @lc code=end
