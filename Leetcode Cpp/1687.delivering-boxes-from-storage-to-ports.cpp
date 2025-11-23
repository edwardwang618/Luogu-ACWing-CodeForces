/*
 * @lc app=leetcode id=1687 lang=cpp
 *
 * [1687] Delivering bs from Storage to Ports
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  const int INF = 2e9;
  int boxDelivering(vector<vector<int>>& bs, int _, int maxB, int maxW) {
    int n = bs.size();
    vector<ll> w(n + 1, 0), c(n + 2, 0);
    for (int i = 1; i <= n; i++) w[i] = w[i - 1] + bs[i - 1][1];
    for (int i = 2; i <= n; i++)
      c[i] = c[i - 1] + (bs[i - 1][0] != bs[i - 2][0]);

    vector<int> f(n + 1);
    deque<int> q;
    q.push_back(0);
    for (int i = 1, j = 0; i <= n; i++) {
      while (q.size() && (i - q.front() > maxB || w[i] - w[q.front()] > maxW))
        q.pop_front();
      f[i] = f[q.front()] + c[i] - c[q.front() + 1] + 2;
      while (q.size() && f[i] - c[i + 1] <= f[q.back()] - c[q.back() + 1])
        q.pop_back();
      q.push_back(i);
    }

    return f[n];
  }
};
// @lc code=end
