/*
 * @lc app=leetcode id=1579 lang=cpp
 *
 * [1579] Remove Max Number of Edges to Keep Graph Fully Traversable
 */

// @lc code=start
class Solution {
public:
  int maxNumEdgesToRemove(int n, vector<vector<int>> &es) {
    vector<int> p1(n), p2(n);
    iota(p1.begin(), p1.end(), 0);
    iota(p2.begin(), p2.end(), 0);

    auto find = [&](this auto &&find, auto& p, int x) -> int {
      return x == p[x] ? x : p[x] = find(p, p[x]);
    };
    auto merge = [&](auto &p, int x, int y) {
      int px = find(p, x), py = find(p, y);
      if (px == py) return false;
      p[px] = py;
      return true;
    };

    int res = 0;
    int c1 = n, c2 = n;
    for (auto &e : es) {
      e[1]--, e[2]--;
      if (e[0] == 3) {
        int x = e[1], y = e[2];
        bool r1 = merge(p1, x, y), r2 = merge(p2, x, y);
        if (r1) c1--;
        if (r2) c2--;
        if (!r1 && !r2) res++;
      }
    }
    
    for (auto &e : es) {
      int x = e[1], y = e[2];
      if (e[0] == 1) {
        if (!merge(p1, x, y)) res++;
        else c1--;
      } else if (e[0] == 2) {
        if (!merge(p2, x, y)) res++;
        else c2--;
      }
    }

    return (c1 == 1 && c2 == 1) ? res : -1;
  }
};
// @lc code=end
