/*
 * @lc app=leetcode id=2976 lang=cpp
 *
 * [2976] Minimum Cost to Convert String I
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  ll minimumCost(string &s, string &t, vector<char> &orig, vector<char> &chan,
                 vector<int> &cost) {
    constexpr ll INF = 9e18;
    vector<vector<ll>> dist(26, vector<ll>(26, INF));
    for (int i = 0; i < 26; i++)
      dist[i][i] = 0;
    for (int i = 0; i < orig.size(); i++) {
      int u = orig[i] - 'a', v = chan[i] - 'a';
      dist[u][v] = min(dist[u][v], (ll)cost[i]);
    }

    for (int k = 0; k < 26; k++)
      for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
          if (dist[i][k] != INF && dist[k][j] != INF)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    ll res = 0;
    for (int i = 0; i < s.size(); i++) {
      int u = s[i] - 'a', v = t[i] - 'a';
      if (dist[u][v] == INF)
        return -1;
      res += dist[u][v];
    }
    return res;
  }
};
// @lc code=end
