/*
 * @lc app=leetcode id=818 lang=cpp
 *
 * [818] Race Car
 */

// @lc code=start
class Solution {
 public:
  struct Node {
    int x, k, d;
    bool operator==(const Node& n) const {
      return x == n.x && k == n.k && d == n.d;
    }
  };

  int racecar(int target) {
    queue<Node> q;
    auto nhash = [](const Node& n) {
      auto h = hash<int>();
      return h(n.x) ^ h(n.k) ^ h(n.d);
    };
    unordered_set<Node, decltype(nhash)> vis(0, nhash);
    q.push({0, 0, 1});
    vis.insert({0, 0, 1});
    int res = 0;
    while (q.size()) {
      res++;
      for (int i = q.size(); i; i--) {
        auto t = q.front(); q.pop();
        int x = t.x + (1 << t.k) * (t.d * 2 - 1);
        if (0 <= x && x <= target * 2) {
          if (x == target) return res;
          if (!vis.count({x, t.k + 1, t.d})) {
            q.push({x, t.k + 1, t.d});
            vis.insert({x, t.k + 1, t.d});
          }
        }

        x = t.x;
        int d = t.d ^ 1;
        if (!vis.count({x, 0, d})) {
          q.push({x, 0, d});
          vis.insert({x, 0, d});
        }
      }
    }
    return -1;
  }
};
// @lc code=end
