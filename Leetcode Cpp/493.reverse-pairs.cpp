/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
// class Solution {
//  public:
// #define lowbit(x) (x & -x)
//   int reversePairs(vector<int>& a) {
//     using ll = long long;
//     vector<ll> tmp{a.begin(), a.end()};
//     for (auto &x : a) tmp.push_back(2ll * x);
//     sort(tmp.begin(), tmp.end());
//     int n = unique(tmp.begin(), tmp.end()) - tmp.begin();
//     unordered_map<ll, int> mp;
//     for (int i = 0; i < n; i++) mp[tmp[i]] = i + 1;

//     vector<int> tr(n + 1);
//     auto add = [&](int k, int x) {
//       for (; k <= n; k += lowbit(k)) tr[k] += x;
//     };
//     auto sum= [&](int k) {
//       int s = 0;
//       for (; k; k -= lowbit(k)) s += tr[k];
//       return s;
//     };

//     int res = 0;
//     for (int i = 0, x; i < a.size(); i++) {
//       x = a[i];
//       res += i - sum(mp[x * 2ll]);
//       add(mp[x], 1);
//     }

//     return res;
//   }
// };

class Solution {
 public:
  int reversePairs(vector<int>& a) {
    using ll = long long;
    int res = 0;
    int n = a.size();
    vector<int> tmp(n);
    auto merge_sort = [&](this auto &&merge_sort, int l, int r) -> int {
      if (l >= r) return 0;
      int mid = l + r >> 1;
      int res = merge_sort(l, mid) + merge_sort(mid + 1, r);
      for (int i = l, j = mid + 1; i <= mid && j <= r; ) {
        if (a[i] > 2ll * a[j]) {
          res += mid - i + 1;
          j++;
        } else i++;
      }
      int i = l, j = mid + 1, idx = l;
      while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[idx++] = a[i++];
        else tmp[idx++] = a[j++];
      }
      while (i <= mid) tmp[idx++] = a[i++];
      while (j <= r) tmp[idx++] = a[j++];
      for (int k = l; k <= r; k++) a[k] = tmp[k];
      return res;
    };
    return merge_sort(0, n - 1);
  }
};
// @lc code=end
