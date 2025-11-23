/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 */

// @lc code=start
class Solution {
 public:
  // vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& es,
  //                                  vector<vector<int>>& qs) {
  //   bool f[n][n];
  //   memset(f, 0, sizeof f);
  //   for (auto& e : es) f[e[0]][e[1]] = true;
  //   for (int k = 0; k < n; k++)
  //     for (int i = 0; i < n; i++)
  //       for (int j = 0; j < n; j++)
  //         if (f[i][k] && f[k][j]) f[i][j] = true;

  //   vector<bool> res;
  //   for (auto& q : qs) res.push_back(f[q[0]][q[1]]);
  //   return res;
  // }

  vector<int> h, e, ne;
  int idx;

#define add(a, b) e[idx] = b, ne[idx] = h[a], h[a] = idx++

  vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& es,
                                   vector<vector<int>>& qs) {
    h.assign(n, -1);
    e.resize(es.size());
    ne.resize(es.size());
    idx = 0;

    int ind[n];
    memset(ind, 0, sizeof ind);
    for (auto& edge : es) {
      int a = edge[0], b = edge[1];
      add(a, b);
      ind[b]++;
    }
    queue<int> q;
    vector<bitset<100>> pre(n);
    for (int i = 0; i < n; i++)
      if (!ind[i]) q.push(i);

    while (q.size()) {
      auto t = q.front(); q.pop();
      auto& pre_set = pre[t];
      for (int i = h[t]; ~i; i = ne[i]) {
        int v = e[i];
        auto& st = pre[v];
        st.set(t);
        st |= pre_set;
        if (!--ind[v]) q.push(v);
      }
    }

    vector<bool> res;
    for (auto& q : qs) res.push_back(pre[q[1]].test(q[0]));
    return res;
  }
};
// @lc code=end
