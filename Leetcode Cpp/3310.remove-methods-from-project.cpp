/*
 * @lc app=leetcode id=3310 lang=cpp
 *
 * [3310] Remove Methods From Project
 */

// @lc code=start
class Solution {
public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>> &es) {
    int m = es.size();
    vector<int> h(n, -1), e(m), ne(m);
    int idx = 0;
    auto add = [&](int a, int b) {
      e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    };
    for (auto &e : es) add(e[0], e[1]);
    vector<bool> sus(n);
    auto dfs = [&](this auto &&dfs, int u) -> void {
      if (sus[u]) return;
      sus[u] = true;
      for (int i = h[u]; ~i; i = ne[i]) dfs(e[i]);
    };
    dfs(k);

    bool can_remove = true;
    for (auto &e : es) 
      if (!sus[e[0]] && sus[e[1]]) {
        can_remove = false;
        break;
      }
    
    vector<int> res;
    if (!can_remove) {
      res.resize(n);
      iota(res.begin(), res.end(), 0);
      return res;
    }

    for (int i = 0; i < n; i++) if (!sus[i]) res.push_back(i);
    return res;
  }
};
// @lc code=end
