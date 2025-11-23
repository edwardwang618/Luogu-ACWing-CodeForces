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
    // mp[x]：x属于哪些线路
    unordered_map<int, unordered_set<int>> mp;
    queue<int> q;
    unordered_set<int> vis;
    for (int i = 0; i < v.size(); i++)
      for (int x : v[i]) {
        if (x == s) {
          q.push(i);
          vis.insert(i);
        }
        mp[x].insert(i);
      }

    int res = 0;
    while (q.size()) {
      res++;
      for (int i = q.size(); i; i--) {
        int id = q.front(); q.pop();
        for (int x : v[id]) {
          if (x == t) return res;
          if (mp.count(x)) {
            for (int y : mp[x]) {
              if (vis.count(y)) continue;
              vis.insert(y);
              q.push(y);
            }
            mp.erase(x);
          }
        }
      }
    }

    return -1;
  }
};
// @lc code=end
