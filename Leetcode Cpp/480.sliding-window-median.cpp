/*
 * @lc app=leetcode id=480 lang=cpp
 *
 * [480] Sliding Window Median
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

  int findk(int k) {
    int l = 1, r = n;
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (sum(mid) >= k) r = mid;
      else l = mid + 1;
    }

    return l;
  }

  vector<double> medianSlidingWindow(vector<int>& A, int k) {
    vector<double> res;
    auto v = A;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    unordered_map<int, int> mp1, mp2;
    for (int i = 0; i < v.size(); i++) mp1[i + 1] = v[i], mp2[v[i]] = i + 1;

    n = mp1.size();
    tr.resize(n + 1, 0);

    for (int i = 0; i < A.size(); i++) {
      add(mp2[A[i]], 1);
      if (i >= k - 1) {
        double x = mp1[findk(k / 2 + 1)];
        if (k & 1) res.push_back(x);
        else res.push_back((mp1[findk(k / 2)] + x) / 2.0);
        add(mp2[A[i - k + 1]], -1);
      }
    }

    return res;
  }
};
// @lc code=end
