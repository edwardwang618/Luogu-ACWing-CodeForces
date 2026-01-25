/*
 * @lc app=leetcode id=2049 lang=cpp
 *
 * [2049] Count Nodes With the Highest Score
 */

// @lc code=start
class Solution {
public:
  int countHighestScoreNodes(vector<int> &ps) {
    int n = ps.size();
    vector<int> h(n, -1), e(n - 1), ne(n - 1);
    int idx = 0;
    auto add = [&](int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; };
    for (int i = 0; i < n; i++)
      if (~ps[i])
        add(ps[i], i);

    using ll = long long;
    ll max_score = 0;
    int cnt = 0;
    auto dfs = [&](this auto &&dfs, int u) -> int {
      int sz = 1;
      ll score = 1;
      for (int i = h[u]; ~i; i = ne[i]) {
        int cnt_sub = dfs(e[i]);
        score *= cnt_sub;
        sz += cnt_sub;
      }
      if (n - sz) score *= n - sz;

      if (score > max_score) max_score = score, cnt = 1;
      else if (score == max_score) cnt++;
      return sz;
    };

    dfs(0);
    return cnt;
  }
};
// @lc code=end
