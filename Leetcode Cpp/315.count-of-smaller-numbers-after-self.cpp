/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
// class Solution {
// public:
//   vector<int> countSmaller(vector<int> &a) {
//     int n = a.size();
//     vector<int> cnt(n), ids(n);
//     iota(ids.begin(), ids.end(), 0);
//     vector<int> tmp(n);
//     auto merge_sort = [&](this auto &&merge_sort, int l, int r) -> void {
//       if (l >= r)
//         return;
//       int mid = l + r >> 1;
//       merge_sort(l, mid), merge_sort(mid + 1, r);
//       int i = l, j = mid + 1, idx = l;
//       while (i <= mid && j <= r) {
//         if (a[ids[i]] <= a[ids[j]]) {
//           cnt[ids[i]] += j - mid - 1;
//           tmp[idx++] = ids[i++];
//         } else
//           tmp[idx++] = ids[j++];
//       }
//       while (i <= mid) {
//         cnt[ids[i]] += j - mid - 1;
//         tmp[idx++] = ids[i++];
//       }
//       while (j <= r)
//         tmp[idx++] = ids[j++];
//       copy(tmp.begin() + l, tmp.begin() + r + 1, ids.begin() + l);
//     };
//     merge_sort(0, n - 1);
//     return cnt;
//   }
// };

class Solution {
public:
  vector<int> countSmaller(vector<int> &a) {
    int n = a.size();
    vector<int> res(n);
    vector<int> cp = a;
    sort(cp.begin(), cp.end());
    unordered_map<int, int> mp;
    int idx = 1;
    for (int i = 0; i < n; i++)
      if (mp.emplace(cp[i], idx).second) idx++;

    vector<int> tr(idx);
    int m = idx - 1;
    auto lowbit = [](int x) { return x & -x; };
    auto add = [&](int k, int x) {
      for (; k <= m; k += lowbit(k)) tr[k] += x;
    };
    auto sum = [&](int k) {
      int res = 0;
      for (; k; k -= lowbit(k)) res += tr[k];
      return res;
    };
    for (int i = n - 1; i >= 0; i--) {
      int x = mp[a[i]];
      res[i] = sum(x - 1);
      add(x, 1);
    }
    return res;
  }
};
// @lc code=end
