/*
 * @lc app=leetcode id=3493 lang=cpp
 *
 * [3493] Properties Graph
 */

// @lc code=start
class Solution {
public:
  int numberOfComponents(vector<vector<int>> &props, int k) {
    int n = props.size();
    static constexpr int N = 101;
    vector<bitset<N>> ss(n);
    for (int i = 0; i < n; i++)
      for (int x : props[i]) ss[i].set(x);

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };

    int res = n;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        auto &small = ss[i], &large = ss[j];
        if ((small & large).count() >= k) {
          int x = find(i), y = find(j);
          if (x != y) {
            p[x] = y;
            res--;
          }
        }
      }
    return res;
  }
};
// @lc code=end
