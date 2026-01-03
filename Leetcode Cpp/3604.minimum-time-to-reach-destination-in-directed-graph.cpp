/*
 * @lc app=leetcode id=3604 lang=cpp
 *
 * [3604] Minimum Time to Reach Destination in Directed Graph
 */

// @lc code=start
class Solution {
public:
  int minTime(int n, vector<vector<int>> &es) {
    int m = es.size();
    vector<int> h(n, -1), e(m), ne(m);
    int idx = 0;
    using PII = pair<int, int>;
    vector<PII> time(m);
    auto add = [&](int a, int b, int st, int ed) {
      e[idx] = b, ne[idx] = h[a], time[idx] = {st, ed}, h[a]= idx++;
    };
    for (auto &e : es) {
      int a = e[0], b = e[1], st = e[2], ed = e[3];
      add(a, b, st, ed);
    }

    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.emplace(0, 0);
    constexpr int INF = 2e9;
    vector<int> dist(n, INF);
    dist[0] = 0;
    while (heap.size()) {
      auto [dis, u] = heap.top(); heap.pop();
      if (dis > dist[u]) continue;
      if (u == n - 1) return dis;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        auto [st, ed] = time[i];
        if (dis > ed) continue;
        int ndis = max(dis, st) + 1;
        if (dist[v] > ndis) {
          dist[v] = ndis;
          heap.emplace(ndis, v);
        }
      }
    }

    return -1;
  }
};
// @lc code=end
