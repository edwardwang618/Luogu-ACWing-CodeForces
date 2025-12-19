/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

// @lc code=start
class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& v, int s, int t) {
    if (s == t) return 0;
    int m = v.size();
    // mp[x]：x属于哪些线路
    unordered_map<int, vector<int>> mp;
    queue<int> q;
    vector<int> vis(m);
    for (int i = 0; i < v.size(); i++) {
      bool hasS = false, hasT = false;
      for (int x : v[i]) {
        if (x == s) {
          hasS = true;
          q.push(i);
          vis[i] = true;
        }
        if (x == t) hasT = true;
        mp[x].push_back(i);
      }
      if (hasS && hasT) return 1;
    }

    int res = 0;
    while (q.size()) {
      res++;
      for (int i = q.size(); i; i--) {
        int id = q.front(); q.pop();
        for (int x : v[id]) {
          if (x == t) return res;
          auto it = mp.find(x);
          if (it != mp.end()) {
            for (int y : it->second)
              if (!vis[y]) {
                vis[y] = true;
                q.push(y);
              }
            mp.erase(it);
          }
        }
      }
    }

    return -1;
  }
};
// @lc code=end
