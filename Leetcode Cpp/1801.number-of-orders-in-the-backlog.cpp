/*
 * @lc app=leetcode id=1801 lang=cpp
 *
 * [1801] Number of Orders in the Backlog
 */

// @lc code=start
class Solution {
 public:
  using PII = pair<int, int>;
#define x first
#define y second
  int getNumberOfBacklogOrders(vector<vector<int>> &orders) {
    static const int MOD = 1e9 + 7;
    priority_queue<PII> buys;
    priority_queue<PII, vector<PII>, greater<>> sells;
    for (auto &o : orders) {
      if (!o[2]) {
        while (sells.size() && sells.top().x <= o[0]) {
          auto p = sells.top();
          sells.pop();
          int cnt = min(p.y, o[1]);
          p.y -= cnt;
          o[1] -= cnt;
          if (p.y) {
            sells.push(p);
            break;
          }
        }
        if (!o[1]) continue;
        if (buys.size() && buys.top().x == o[0]) {
          auto p = buys.top();
          buys.pop();
          p.y += o[1];
          buys.push(p);
        } else
          buys.emplace(o[0], o[1]);
      } else {
        while (buys.size() && buys.top().x >= o[0]) {
          auto p = buys.top();
          buys.pop();
          int cnt = min(p.y, o[1]);
          p.y -= cnt;
          o[1] -= cnt;
          if (p.y) {
            buys.push(p);
            break;
          }
        }
        if (!o[1]) continue;
        if (sells.size() && sells.top().x == o[0]) {
          auto p = sells.top();
          sells.pop();
          p.y += o[1];
          sells.push(p);
        } else
          sells.emplace(o[0], o[1]);
      }
    }

    int res = 0;
    for (; buys.size(); buys.pop()) res = (res + buys.top().y) % MOD;
    for (; sells.size(); sells.pop()) res = (res + sells.top().y) % MOD;
    return res;
  }
};
// @lc code=end
