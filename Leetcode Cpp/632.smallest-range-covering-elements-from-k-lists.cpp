/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 */

// @lc code=start
class Solution {
public:
  vector<int> smallestRange(vector<vector<int>> &a) {
    using T = tuple<int, int, int>;
    priority_queue<T, vector<T>, greater<>> heap;
    vector<int> res;
    int cur_max = -2e9;
    for (int i = 0; i < a.size(); i++) {
      auto &v = a[i];
      heap.emplace(v[0], i, 0);
      cur_max = max(cur_max, v[0]);
    }

    int min_len = 2e9;
    while (heap.size()) {
      auto [x, i, j] = heap.top(); heap.pop();
      int cur_len = cur_max - x;
      if (cur_len < min_len) {
        res = {x, cur_max};
        min_len = cur_len;
      }
      if (j + 1 < a[i].size()) {
        heap.emplace(a[i][j + 1], i, j + 1);
        cur_max = max(cur_max, a[i][j + 1]);
      } else break;
    }
    return res;
  }
};
// @lc code=end
