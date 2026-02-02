/*
 * @lc app=leetcode id=3629 lang=cpp
 *
 * [3629] Minimum Jumps to Reach End via Prime Teleportation
 */

// @lc code=start
class Solution {
public:
  int minJumps(vector<int> &a) {
    int n = a.size();
    if (n == 1) return 0;

    unordered_map<int, vector<int>> mp;
    unordered_set<int> st(a.begin(), a.end());
    for (int i = n - 1; i >= 0; i--) {
      int x = a[i];
      for (int p = 2; p <= x / p; p++) {
        if (x % p == 0) {
          if (st.count(p)) mp[p].push_back(i);
          while (x % p == 0) x /= p;
        }
      }
      if (x > 1 && st.count(x)) mp[x].push_back(i);
    }
    
    queue<int> q{{0}};
    vector<bool> vis(n);
    vis[0] = true;
    int step = 0;
    while (q.size()) {
      step++;
      for (int _ = q.size(); _--;) {
        int u = q.front(); q.pop();
        for (int v : {u - 1, u + 1})
          if (0 <= v && v < n && a[v]) {
            if (v == n - 1) return step;
            if (!vis[v]) {
              vis[v] = true;
              q.push(v);
            }
          }
        if (auto it = mp.find(a[u]); it != mp.end()) {
          for (int v : it->second) {
            if (v == n - 1) return step;
            if (!vis[v]) {
              vis[v] = true;
              q.push(v);
            }
          }
          mp.erase(it);
        }
      }
    }
    return -1;
  }
};
// @lc code=end
