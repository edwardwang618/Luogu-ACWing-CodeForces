/*
 * @lc app=leetcode id=1654 lang=cpp
 *
 * [1654] Minimum Jumps to Reach Home
 */

// @lc code=start
class Solution {
public:
  int minimumJumps(vector<int> &forb, int a, int b, int x) {
    if (!x) return 0;
    int maxPos = max(x, *max_element(forb.begin(), forb.end())) + a + b;
    unordered_set<int> st(forb.begin(), forb.end());
    vector<array<bool, 2>> vis(maxPos + 1, {false, false});

    queue<pair<int, bool>> q;
    q.emplace(0, false);
    vis[0][0] = true;

    int res = 0;
    while (!q.empty()) {
      res++;
      for (int i = q.size(); i; i--) {
        auto [pos, back] = q.front(); q.pop();
        int nxt = pos + a;
        if (nxt == x)
          return res;
        if (nxt <= maxPos && !st.count(nxt) && !vis[nxt][0]) {
          vis[nxt][0] = true;
          q.emplace(nxt, false);
        }

        if (!back) {
          nxt = pos - b;
          if (nxt == x)
            return res;
          if (nxt >= 0 && !st.count(nxt) && !vis[nxt][1]) {
            vis[nxt][1] = true;
            q.emplace(nxt, true);
          }
        }
      }
    }

    return -1;
  }
};
// @lc code=end
