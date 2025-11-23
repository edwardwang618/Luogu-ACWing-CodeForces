/*
 * @lc app=leetcode id=2035 lang=cpp
 *
 * [2035] Partition Array Into Two Arrays to Minimize Sum Difference
 */

// @lc code=start
class Solution {
 public:
  int minimumDifference(vector<int> &a) {
    int n = a.size() / 2, res = INT_MAX;
    unordered_map<int, set<long>> mp;
    dfs(n, 0, 0, a, mp);
    long sum = 0;
    for (int x : a) sum += x;
    for (int i = 0; i < 1 << n; i++) {
      int cnt = 0;
      long s = 0;
      for (int k = 0, t = i; t; k++) {
        if (t & 1) {
          s += a[k];
          cnt++;
        }
        t >>= 1;
      }
      auto &st = mp[n - cnt];
      auto it = st.lower_bound(sum / 2 - s);
      if (it != st.end()) res = min(res, (int)abs(sum - 2 * (*it + s)));
      if (it != st.begin()) res = min(res, (int)abs(sum - 2 * (*(--it) + s)));
    }

    return res;
  }

  void dfs(int u, int cnt, int sum, vector<int> &a,
           unordered_map<int, set<long>> &mp) {
    mp[cnt].insert(sum);
    for (int i = u; i < a.size(); i++) dfs(i + 1, cnt + 1, sum + a[i], a, mp);
  }
};
// @lc code=end
