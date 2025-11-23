/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
 public:
  bool canFinish(int n, vector<vector<int>>& pre) {
    int ind[n];
    fill(ind, ind + n, 0);
    unordered_map<int, vector<int>> g;
    for (auto &e : pre) {
      int a = e[0], b = e[1];
      g[b].push_back(a);
      ind[a]++;
    }
        
    queue<int> q;
    for (int i = 0; i < n; i++)
      if (!ind[i]) q.push(i);

    int cnt = 0;
    while (q.size()) {
      int t = q.front(); q.pop();
      cnt++;
      for (auto &x : g[t]) {
        ind[x]--;
        if (!ind[x]) q.push(x);
      }
    }

    return cnt == n;
  }
};
// @lc code=end
