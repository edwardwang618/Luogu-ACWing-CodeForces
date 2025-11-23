/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 */

// @lc code=start
class Solution {
 public:
  // int shortestSubarray(vector<int>& a, int k) {
  //   int n = a.size();
  //   vector<long> p(n + 1, 0);
  //   for (int i = 0; i < n; i++) p[i + 1] = p[i] + a[i];
  //   deque<int> dq;
  //   int res = n + 1;
  //   for (int i = 0; i <= n; i++) {
  //     while (dq.size() && p[dq.back()] >= p[i]) dq.pop_back();
  //     while (dq.size() && p[dq.front()] <= p[i] - k) {
  //       res = min(res, i - dq.front());
  //       dq.pop_front();
  //     }
  //     dq.push_back(i);
  //   }

  //   return res == n + 1 ? -1 : res;
  // }

  int shortestSubarray(vector<int>& a, int k) {
    int n = a.size();
    vector<long> p(n + 1, 0);
    for (int i = 0; i < n; i++) p[i + 1] = p[i] + a[i];
    int res = n + 1;
    vector<int> stk(n + 1);
    int top = 0;
    for (int i = 0; i <= n; i++) {
      while (top && p[stk[top - 1]] >= p[i]) top--;
      if (top) {
        int l = 0, r = top - 1;
        while (l < r) {
          int mid = l + (r - l + 1 >> 1);
          if (p[i] - p[stk[mid]] >= k) l = mid;
          else r = mid - 1;
        }

        if (p[i] - p[stk[l]] >= k) res = min(res, i - stk[l]);
      }
      stk[top++] = i;
    }

    return res == n + 1 ? -1 : res;
  }
};
// @lc code=end
