/*
 * @lc app=leetcode id=2737 lang=cpp
 *
 * [2737] Find the Closest Marked Node
 */

// @lc code=start
class Solution {
public:
  int minimumDistance(int n, vector<vector<int>> &es, int s,
                      vector<int> &marked) {
    unordered_set<int> st(marked.begin(), marked.end());
    if (st.count(s)) return 0;
    int m = es.size();
    vector<int> h(n, -1), e(m), ne(m), w(m);
    int idx = 0;
    auto add = [&](int a, int b, int c) {
      e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    };
    for (auto &e : es) add(e[0], e[1], e[2]);

    constexpr int INF = 2e9;
    vector<int> dist(n, INF);
    dist[s] = 0;
    using PII = pair<int, int>;
    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.emplace(0, s);
    while (heap.size()) {
      auto [dis, u] = heap.top(); heap.pop();
      if (dis > dist[u]) continue;
      if (st.count(u)) return dis;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i], c = w[i];
        if (dis + c < dist[v]) {
          dist[v] = dis + c;
          heap.emplace(dist[v], v);
        }
      }
    }
    return -1;
  }
};
// @lc code=end
