/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution {
 public:
  int len;
  bool makesquare(vector<int> &A) {
    len = 0;
    for (auto &x : A) len += x;
    if (len % 4) return false;
    len /= 4;

    sort(A.begin(), A.end(), greater<int>());
    vector<bool> vis(A.size(), 0);
    return dfs(0, 0, 0, A, vis);
  }

  bool dfs(int u, int cur_len, int cnt, vector<int> &A, vector<bool> &vis) {
    if (cnt == 3) return true;
    if (cur_len == len) return dfs(0, 0, cnt + 1, A, vis);

    for (int i = u; i < A.size(); i++) {
      if (vis[i]) continue;
      if (cur_len + A[i] > len) continue;
      cur_len += A[i];
      vis[i] = true;
      if (dfs(u + 1, cur_len, cnt, A, vis)) return true;
      cur_len -= A[i];
      vis[i] = false;
      if (!cur_len || cur_len + A[i] == len) return false;
      while (i + 1 < A.size() && A[i + 1] == A[i]) i++;
    }

    return false;
  }
};
// @lc code=end
