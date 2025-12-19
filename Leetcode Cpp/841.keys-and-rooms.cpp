/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rs) {
    vector<bool> vis(rs.size());
    return dfs(0, rs, vis) == rs.size();
  }

  static int dfs(int u, auto &rs, auto &vis) {
    vis[u] = true;
    int cnt = 1;
    for (int ne : rs[u])
      if (!vis[ne])
        cnt += dfs(ne, rs, vis);
    return cnt;
  }
};
// @lc code=end
