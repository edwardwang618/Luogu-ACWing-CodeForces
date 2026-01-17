/*
 * @lc app=leetcode id=2242 lang=cpp
 *
 * [2242] Maximum Score of a Node Sequence
 */

// @lc code=start
class Solution {
public:
  int maximumScore(vector<int> &ss, vector<vector<int>> &es) {
    int n = ss.size();
    using PII = pair<int, int>;
    // {score, node}
    vector<vector<PII>> top3(n);

    for (auto &e : es) {
      int u = e[0], v = e[1];
      top3[u].emplace_back(ss[v], v);
      top3[v].emplace_back(ss[u], u);
    }

    for (int i = 0; i < n; i++) {
      auto &v = top3[i];
      if (v.size() > 3) {
        nth_element(v.begin(), v.begin() + 3, v.end(), greater<>());
        v.resize(3);
      }
      sort(v.begin(), v.end(), greater<>());
    }

    int res = -1;
    for (auto &e : es) {
      int b = e[0], c = e[1];
      for (auto &[sa, a] : top3[b]) {
        if (a == c) continue;
        for (auto &[sd, d] : top3[c]) {
          if (d == b || d == a) continue;
          res = max(res, ss[a] + ss[b] + ss[c] + ss[d]);
          break;
        }
      }
    }

    return res;
  }
};
// @lc code=end
