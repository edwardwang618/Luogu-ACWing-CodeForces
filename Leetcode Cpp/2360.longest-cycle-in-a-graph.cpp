/*
 * @lc app=leetcode id=2360 lang=cpp
 *
 * [2360] Longest Cycle in a Graph
 */
class Solution {
 public:
  int longestCycle(vector<int>& e) {
    int n = e.size();
    vector<bool> vis(n);
    int res = -1;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        unordered_map<int, int> mp;
        int x = i, time_stamp = 0;
        while (true) {
          mp[x] = ++time_stamp;
          vis[x] = true;
          if (mp.count(e[x])) {
            res = max(res, mp[x] - mp[e[x]] + 1);
            break;
          }
          if (e[x] == -1 || vis[e[x]]) break;
          x = e[x];
        }
      }
    }

    return res;
  }
};
// @lc code=start
