/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution {
public:
  vector<string> findItinerary(vector<vector<string>> &ts) {
    vector<string> res;
    unordered_map<string, priority_queue<string, vector<string>, greater<>>> g;
    for (auto &v : ts)
      g[v[0]].push(v[1]);
    dfs("JFK", g, res);
    reverse(res.begin(), res.end());
    return res;
  }

  static void dfs(string s, auto &g, auto &res) {
    if (auto it = g.find(s); it != g.end()) {
      auto &heap = it->second;
      while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        dfs(t, g, res);
      }
    }

    res.push_back(s);
  }
};
// @lc code=end
