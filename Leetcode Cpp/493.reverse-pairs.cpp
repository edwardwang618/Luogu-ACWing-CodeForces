/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution {
 public:
  #define lowbit(x) (x & -x)
  vector<int> tr;
  int n;

  void add(int k, int x) {
    for (; k <= n; k += lowbit(k)) tr[k] += x;
  }

  int sum(int k) {
    int res = 0;
    for (; k; k -= lowbit(k)) res += tr[k];
    return res;
  }

  int reversePairs(vector<int>& A) {
    vector<long> tmp(A.begin(), A.end());
    for (auto &x : A) tmp.push_back(2L * x);
    sort(tmp.begin(), tmp.end());
    n = unique(tmp.begin(), tmp.end()) - tmp.begin();
    unordered_map<long, int> mp;
    for (int i = 0; i < n; i++) mp[tmp[i]] = i + 1;
    tr = vector<int>(n + 1);

    int res = 0;
    for (int i = 0, x; i < A.size(); i++) {
      x = A[i];
      res += i - sum(mp[x * 2L]);
      add(mp[x], 1);
    }

    return res;
  }
};
// @lc code=end
