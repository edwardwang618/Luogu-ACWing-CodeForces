/*
 * @lc app=leetcode id=3036 lang=cpp
 *
 * [3036] Number of Subarrays That Match a Pattern II
 */

// @lc code=start
class Solution {
public:
  int countMatchingSubarrays(vector<int> &a, vector<int> &p) {
    int n = a.size(), m = p.size();
    if (n - 1 < m) return 0;
    vector<int> s(n);
    for (int i = 1; i < n; i++)
      s[i] = (a[i] > a[i - 1]) - (a[i] < a[i - 1]);
    p.insert(p.begin(), 0);
    auto ne = [&](auto &p) {
      vector<int> ne(m + 1);
      for (int i = 2, j = 0; i <= m; i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
      }
      return ne;
    }(p);

    int res = 0;
    for (int i = 1, j = 0; i <= n - 1; i++) {
      while (j && s[i] != p[j + 1]) j = ne[j];
      if (s[i] == p[j + 1]) j++;
      if (j == m) {
        res++;
        j = ne[j];
      }
    }

    return res;
  }
};
// @lc code=end
