/*
 * @lc app=leetcode id=2359 lang=cpp
 *
 * [2359] Find Closest Node to Given Two Nodes
 */

// @lc code=start
class Solution {
 public:
  int closestMeetingNode(vector<int>& g, int node1, int node2) {
    int n = g.size();
    vector<int> dist1(n, -1), dist2(n, -1);
    bfs(node1, g, dist1);
    bfs(node2, g, dist2);
    int mind = INT_MAX, res = -1;
    for (int i = 0; i < n; i++) {
      int d = -1;
      if (~dist1[i] && ~dist2[i]) d = max(d, max(dist1[i], dist2[i]));
      if (~d && d < mind) {
        mind = min(mind, d);
        res = i;
      }
    }

    return res;
  }

  void bfs(int u, vector<int>& g, vector<int>& dist) {
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    while (q.size()) {
      int t = q.front();
      q.pop();
      int ne = g[t];
      if (~ne && dist[ne] == -1) {
        dist[ne] = dist[t] + 1;
        q.push(ne);
      }
    }
  }
};
// @lc code=end
