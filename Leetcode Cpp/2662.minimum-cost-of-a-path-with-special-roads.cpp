/*
 * @lc app=leetcode id=2662 lang=cpp
 *
 * [2662] Minimum Cost of a Path With Special Roads
 */

// @lc code=start
class Solution {
public:
  int minimumCost(vector<int> &st, vector<int> &t, vector<vector<int>> &es) {
    auto pair_to_string = [&](int x, int y) {
      return to_string(x) + " " + to_string(y);
    };
    unordered_map<string, int> dist;
    string start = pair_to_string(st[0], st[1]), end = pair_to_string(t[0], t[1]);
    dist[start] = 0;
    using PIS = pair<int, string>;
    priority_queue<PIS, vector<PIS>, greater<>> heap;
    heap.emplace(0, start);
    auto to_pair = [](string &s) {
      int x, y;
      sscanf(s.c_str(), "%d %d", &x, &y);
      return make_pair(x, y);
    };
    auto man_dist = [](int x1, int y1, int x2, int y2) {
      return abs(x1 - x2) + abs(y1 - y2);
    };
    while (heap.size()) {
      auto [dis, pos] = heap.top(); heap.pop();
      if (auto it = dist.find(pos); it != dist.end() && dis > it->second) 
        continue;
      if (pos == end) return dis;
      auto [x, y] = to_pair(pos);
      int to_end = dis + man_dist(x, y, t[0], t[1]);
      auto [it, ins] = dist.emplace(end, to_end); 
      if (ins || it->second > to_end) {
        it->second = to_end;
        heap.emplace(to_end, end);
      }
      for (auto &e : es) {
        int x1 = e[0], y1 = e[1], x2 = e[2], y2 = e[3], w = e[4];
        int ne_dist = dis + man_dist(x, y, x1, y1) + w;
        string ne = pair_to_string(x2, y2);
        auto [it, ins] = dist.emplace(ne, ne_dist); 
        if (ins || it->second > ne_dist) {
          it->second = ne_dist;
          heap.emplace(ne_dist, ne);
        }
      }
    }

    return -1;
  }
};
// @lc code=end
