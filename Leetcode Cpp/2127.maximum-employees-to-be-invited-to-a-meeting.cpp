/*
 * @lc app=leetcode id=2127 lang=cpp
 *
 * [2127] Maximum Employees to Be Invited to a Meeting
 */

// @lc code=start
class Solution {
 public:
  int maximumInvitations(vector<int>& fs) {
    int n = fs.size();
    vector<int> ind(n);
    for (int i = 0; i < n; i++) ind[fs[i]]++;
    queue<int> q;
    for (int i = 0; i < n; i++)
      if (!ind[i]) q.push(i);
    vector<int> len(n);
    vector<bool> vis(n);
    while (q.size()) {
      int t = q.front();
      q.pop();
      vis[t] = true;
      int ne = fs[t];
      len[ne] = max(len[ne], len[t] + 1);
      if (!--ind[ne]) q.push(ne);
    }

    int res = 0;
    vector<vector<int>> c2;
    for (int i = 0; i < n; i++)
      if (!vis[i]) {
        int cnt = 1;
        vector<int> v;
        vis[i] = true;
        v.push_back(i);
        for (int x = i; fs[x] != i; x = fs[x]) {
          v.push_back(fs[x]);
          vis[fs[x]] = true;
          cnt++;
        }
        if (cnt == 2)
          c2.push_back(v);
        else
          res = max(res, cnt);
      }

    int cnt = 2 * c2.size();
    for (auto& v : c2) cnt += len[v[0]] + len[v[1]];

    res = max(res, cnt);
    return res;
  }
};
// @lc code=end
