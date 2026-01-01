/*
 * @lc app=leetcode id=2642 lang=cpp
 *
 * [2642] Design Graph With Shortest Path Calculator
 */

// @lc code=start
class Graph {
public:
  int n;
  vector<vector<int>> dist;
  static constexpr int INF = 2e9;
  Graph(int n, vector<vector<int>> &es) {
    this->n = n;
    dist.resize(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
      dist[i][i] = 0;
    for (auto &e : es) {
      int x = e[0], y = e[1];
      dist[x][y] = min(dist[x][y], e[2]);
    }
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (dist[i][k] != INF && dist[k][j] != INF)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  }

  void addEdge(vector<int> e) {
    int u = e[0], v = e[1], w = e[2];
    if (w >= dist[u][v])
      return;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (dist[i][u] != INF && dist[v][j] != INF)
          dist[i][j] = min(dist[i][j], dist[i][u] + w + dist[v][j]);
  }

  int shortestPath(int u, int v) {
    if (dist[u][v] == INF)
      return -1;
    return dist[u][v];
  }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
// @lc code=end
