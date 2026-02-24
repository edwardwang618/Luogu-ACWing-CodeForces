/*
 * @lc app=leetcode id=2508 lang=cpp
 *
 * [2508] Add Edges to Make Degrees of All Nodes Even
 */

// @lc code=start
class Solution {
 public:
  bool isPossible(int n, vector<vector<int>>& es) {
    using PII = pair<int, int>;
    auto ha = [](const PII& p) {
      using ll = long long;
      return hash<ll>{}((ll)p.first << 32 | p.second);
    };
    unordered_set<PII, decltype(ha)> g;
    vector<int> deg(n + 1);
    for (auto& e : es) {
      int u = e[0], v = e[1];
      deg[u]++;
      deg[v]++;
      g.emplace(min(u, v), max(u, v));
    }

    vector<int> vs;
    for (int i = 1; i <= n; i++)
      if (deg[i] & 1) vs.push_back(i);

    if (vs.empty()) return true;
    auto has = [&](int u, int v) {
      return g.count({min(u, v), max(u, v)});
    };
    if (vs.size() == 2) {
      int u = vs[0], v = vs[1];
      if (!has(u, v)) return true;
      for (int w = 1; w <= n; w++)
        if (w != u && w != v && !has(w, u) && !has(w, v)) return true;
      return false;
    }

    if (vs.size() == 4) {
      for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
          vector<int> a = {vs[i], vs[j]};
          vector<int> b;
          for (int k = 0; k < 4; k++)
            if (k != i && k != j) b.push_back(vs[k]);

          if (!has(a[0], a[1]) && !has(b[0], b[1])) return true;
        }
      }
    }

    return false;
  }
};
// @lc code=end
