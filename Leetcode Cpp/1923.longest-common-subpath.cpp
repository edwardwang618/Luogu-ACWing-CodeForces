/*
 * @lc app=leetcode id=1923 lang=cpp
 *
 * [1923] Longest Common Subpath
 */

// @lc code=start
class Solution {
 public:
  using ULL = unsigned long long;
  int longestCommonSubpath(int n, vector<vector<int>>& ps) {
    int l = 0, r = INT_MAX;
    for (auto& p : ps) r = min(r, (int)p.size());
    ULL P = 100001, mod = 100000000019;
    while (l < r) {
      int mid = l + (r - l + 1 >> 1);
      unordered_set<ULL> hs;
      for (int i = 0; i < ps.size(); i++) {
        ULL ha = 0, pow = 1;
        unordered_set<ULL> hs_tmp;
        for (int j = 0; j < ps[i].size(); j++) {
          ha = (ha * P + ps[i][j]) % mod;
          if (j >= mid) ha = (mod + ha - pow * ps[i][j - mid] % mod) % mod;
          else pow = pow * P % mod;
          if (j >= mid - 1 && (!i || hs.count(ha))) hs_tmp.insert(ha);
        }
        hs.swap(hs_tmp);
        if (hs.empty()) break;
      }
      if (hs.size()) l = mid;
      else r = mid - 1;
    }

    return l;
  }
};
// @lc code=end
