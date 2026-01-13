/*
 * @lc app=leetcode id=3594 lang=cpp
 *
 * [3594] Minimum Time to Transport All Individuals
 */

// @lc code=start
class Solution {
public:
  double minTime(int n, int k, int m, vector<int> &time, vector<double> &mul) {
    if (k == 1 && n > 1)
      return -1.0;

    const int FULL = (1 << n) - 1;
    const double INF = 1e100;

    // max time in any subset
    vector<int> max_time(1 << n, 0);
    for (int mask = 1; mask <= FULL; ++mask) {
      int b = countr_zero((unsigned)mask);
      int pm = mask & (mask - 1);
      max_time[mask] = max(max_time[pm], time[b]);
    }

    // dist[side][stage][mask]
    auto id = [&](int side, int stage, int mask) {
      return (side * m + stage) * (1 << n) + mask;
    };
    vector<double> dist(2 * m * (1 << n), INF);

    struct Node {
      double d;
      int side, stage, mask;
      bool operator<(Node const &o) const { return d > o.d; }
    };
    priority_queue<Node> heap;

    dist[id(0, 0, FULL)] = 0.0;
    heap.emplace(0.0, 0, 0, FULL);
    while (!heap.empty()) {
      auto [dis, side, stage, mask] = heap.top();
      heap.pop();
      if (dis > dist[id(side, stage, mask)]) continue;
      if (!mask && side == 1) return dis;
      if (side == 0) {
        for (int sub = mask; sub; sub = (sub - 1) & mask) {
          if (popcount((unsigned)sub) > k) continue;
          double t = (double)max_time[sub] * mul[stage];
          int step = ((int)floor(t)) % m;
          int ne_stage = (stage + step) % m;
          int ne_mask = mask ^ sub;
          double ndis = dis + t;
          int nid = id(1, ne_stage, ne_mask);
          if (ndis < dist[nid]) {
            dist[nid] = ndis;
            heap.emplace(ndis, 1, ne_stage, ne_mask);
          }
        }
      } else {
        int right = (~mask) & FULL;
        while (right) {
          int i = countr_zero((unsigned)right);
          right &= right - 1;
          double t = (double)time[i] * mul[stage];
          int step = ((int)floor(t)) % m;
          int ne_stage = (stage + step) % m;
          int ne_mask = mask ^ (1 << i);
          double ndis = dis + t;
          int nid = id(0, ne_stage, ne_mask);
          if (ndis < dist[nid]) {
            dist[nid] = ndis;
            heap.emplace(ndis, 0, ne_stage, ne_mask);
          }
        }
      }
    }

    return -1.0;
  }
};
// @lc code=end
