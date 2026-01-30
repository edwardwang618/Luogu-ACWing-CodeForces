/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
class Solution {
public:
  int removeStones(vector<vector<int>> &ss) {
    int n = ss.size();
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };

    unordered_map<int, int> row, col;
    for (int i = 0; i < n; i++) {
      int x = ss[i][0], y = ss[i][1];
      if (auto [it, ins] = row.emplace(x, i); !ins) p[find(i)] = find(it->second);
      if (auto [it, ins] = col.emplace(y, i); !ins) p[find(i)] = find(it->second); 
    }

    int cnt = n;
    for (int i = 0; i < n; i++) if (i == find(i)) cnt--;
    return cnt;
  }
};
// @lc code=end
