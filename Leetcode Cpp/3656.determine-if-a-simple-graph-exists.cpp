/*
 * @lc app=leetcode id=3656 lang=cpp
 *
 * [3656] Determine if a Simple Graph Exists
 */

// @lc code=start
class Solution {
public:
  bool simpleGraphExists(vector<int> &ds) {
    int n = ds.size();
    using ll = long long;
    ll sum = 0;
    for (int x : ds) sum += x;
    if (sum % 2) return false;

    sort(ds.begin(), ds.end(), greater<>{});
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + ds[i];

    for (int k = 1; k <= n; k++) {
      ll left = pre[k];
      ll right = (ll)k * (k - 1);
      int l = k, r = n - 1;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (ds[mid] < k) r = mid;
        else l = mid + 1;
      }
      int j = l;
      
      // [k, j): ds[i] >= k
      // [j, n): ds[i] < k
      right += (ll)(j - k) * k + (pre[n] - pre[j]);
      
      if (left > right) return false;
    }
    return true;
  }
};
// @lc code=end
