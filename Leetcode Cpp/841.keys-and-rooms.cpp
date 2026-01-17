/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rs) {
    int n = rs.size();
    vector<bool> vis(n);
    auto dfs = [&](this auto &&dfs, int u) -> int {
      vis[u] = true;
      int cnt = 1;
      for (int ne : rs[u])
        if (!vis[ne])
          cnt += dfs(ne);
      return cnt;
    };
    return dfs(0) == n;
  }
};
// @lc code=end
