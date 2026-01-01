/*
 * @lc app=leetcode id=444 lang=cpp
 *
 * [444] Sequence Reconstruction
 */

// @lc code=start
class Solution {
public:
  bool sequenceReconstruction(vector<int> &a, vector<vector<int>> &seq) {
    int n = a.size(), m = 0;
    for (auto &se : seq) m += se.size() - 1;
    vector<int> h(n + 1, -1), e(m), ne(m);
    int idx = 0;
    auto add = [&](int a, int b) {
      e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    };
    vector<int> ind(n + 1);
    for (auto &se : seq)
      for (int i = 0; i + 1 < se.size(); i++) {
        add(se[i], se[i + 1]);
        ind[se[i + 1]]++;
      }

    queue<int> q;
    for (int i = 1; i <= n; i++) if (!ind[i]) q.push(i);
    idx = 0;
    while (q.size()) {
      if (q.size() > 1) return false;
      int x = q.front(); q.pop();
      if (x != a[idx++]) return false;
      for (int i = h[x]; ~i; i = ne[i]) {
        int y = e[i];
        if (!--ind[y]) q.push(y);
      }
    }
    return true;
  }
};
// @lc code=end
