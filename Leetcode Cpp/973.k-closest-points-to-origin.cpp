/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
 public:
  // vector<vector<int>> kClosest(vector<vector<int>>& ps, int k) {
  //   auto dis = [](auto& p) { return p[0] * p[0] + p[1] * p[1]; };
  //   auto cmp = [&](auto& p1, auto& p2) { return dis(p1) < dis(p2); };
  //   priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)>
  //   heap(cmp); for (int i = 0; i < k; i++) heap.push(ps[i]); for (int i = k;
  //   i < ps.size(); i++)
  //     if (dis(ps[i]) < dis(heap.top())) {
  //       heap.pop();
  //       heap.push(ps[i]);
  //     }

  //   vector<vector<int>> res;
  //   for (int i = 0; i < k; i++) {
  //     res.push_back(heap.top());
  //     heap.pop();
  //   }

  //   return res;
  // }

  vector<vector<int>> kClosest(vector<vector<int>>& ps, int k) {
    auto dis = [](auto& p) { return p[0] * p[0] + p[1] * p[1]; };
    quick_select(ps, 0, ps.size() - 1, k - 1, dis);
    return vector<vector<int>>(ps.begin(), ps.begin() + k);
  }

  void quick_select(vector<vector<int>>& ps, int l, int r, int rk, auto& dis) {
    if (l >= r) return;
    int i = l, j = r;
    int piv_dis = dis(ps[l + (r - l >> 1)]);
    while (i <= j) {
      while (dis(ps[i]) < piv_dis) i++;
      while (dis(ps[j]) > piv_dis) j--;
      if (i <= j) swap(ps[i++], ps[j--]);
    }
    if (rk <= j) quick_select(ps, l, j, rk, dis);
    if (rk >= i) quick_select(ps, i, r, rk, dis);
  }
};
// @lc code=end
