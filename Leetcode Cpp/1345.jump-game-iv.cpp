/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */

// @lc code=start
class Solution {
 public:
  int minJumps(vector<int> &a) {
    int n = a.size();
    if (n == 1) return 0;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) mp[a[i]].push_back(i);
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    int res = 0;
    while (!q.empty()) {
      res++;
      for (int _ = q.size(); _; _--) {
        int t = q.front();
        q.pop();
        for (auto &ne : mp[a[t]]) {
          if (ne == t || vis[ne]) continue;
          if (ne == n - 1) return res;
          q.push(ne);
          vis[ne] = true;
        }
        mp[a[t]].clear();
        if (t - 1 >= 0 && !vis[t - 1]) {
          q.push(t - 1);
          vis[t - 1] = true;
        }
        if (t + 1 < n && !vis[t + 1]) {
          if (t + 1 == n - 1) return res;
          q.push(t + 1);
          vis[t + 1] = true;
        }
      }
    }

    return -1;
  }
};
// @lc code=end
