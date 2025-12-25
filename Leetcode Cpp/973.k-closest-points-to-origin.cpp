/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
public:
  // vector<vector<int>> kClosest(vector<vector<int>> &ps, int k) {
  //   int n = ps.size();
  //   vector<int> dist(n, -1);
  //   auto dis = [&](int i) { 
  //     if (~dist[i]) return dist[i];
  //     auto &p = ps[i];
  //     return dist[i] = p[0] * p[0] + p[1] * p[1]; 
  //   };
  //   auto cmp = [&](int i, int j) { return dis(i) < dis(j); };
  //   priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);
  //   for (int i = 0; i < ps.size(); i++) {
  //     if (i < k) heap.push(i);
  //     else if (dis(i) < dis(heap.top())) {
  //       heap.pop();
  //       heap.push(i);
  //     }
  //   }

  //   vector<vector<int>> res;
  //   while (heap.size()) {
  //     int i = heap.top(); heap.pop();
  //     res.push_back(ps[i]);
  //   }
  //   return res;
  // }

  vector<vector<int>> kClosest(vector<vector<int>>& ps, int k) {
    auto dis = [](auto& p) { return p[0] * p[0] + p[1] * p[1]; };
    auto quick_select = [&](int l, int r, int k) {
      while (l < r) {
        int i = l, j = r, piv = dis(ps[l + r >> 1]);
        while (i <= j) {
          while (dis(ps[i]) < piv) i++;
          while (dis(ps[j]) > piv) j--;
          if (i <= j) swap(ps[i++], ps[j--]);
        }
        if (k <= j) r = j;
        else if (k >= i) l = i;
        else return;
      }
    };
    quick_select(0, ps.size() - 1, k - 1);
    return {ps.begin(), ps.begin() + k};
  }
};
// @lc code=end
