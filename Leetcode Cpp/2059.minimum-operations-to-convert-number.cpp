/*
 * @lc app=leetcode id=2059 lang=cpp
 *
 * [2059] Minimum Operations to Convert Number
 */

// @lc code=start
class Solution {
public:
  int minimumOperations(vector<int> &a, int s, int e) {
    if (s == e) return 0;
    static constexpr int N = 1001;
    bitset<N> vis;
    queue<int> q{{s}};
    vis.set(s);
    int step = 0;
    auto in_range = [](int x) { return 0 <= x && x <= 1000; };
    while (q.size()) {
      step++;
      for (int _ = q.size(); _--;) {
        int x = q.front(); q.pop();
        int ne;
        for (int y : a)
          for (int ne : {x + y, x - y, x ^ y}) {
            if (ne == e) return step;
            if (0 <= ne && ne <= 1000 && !vis[ne]) {
              vis.set(ne);
              q.push(ne);
            }
          }
      }
    }
    return -1;
  }
};
// @lc code=end
