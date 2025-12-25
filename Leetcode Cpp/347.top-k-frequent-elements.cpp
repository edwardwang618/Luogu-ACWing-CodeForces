/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
  vector<int> topKFrequent(vector<int> &a, int k) {
    int n = a.size();
    unordered_map<int, int> mp;
    for (int x : a) ++mp[x];
    a.clear();
    for (auto [k, _] : mp) a.push_back(k);
    n = a.size();
    int l = 0, r = n - 1;
    k = n - k;
    while (l < r) {
      int i = l, j = r, piv = a[l + r >> 1];
      while (i <= j) {
        int fr = mp[piv];
        while (mp[a[i]] < fr) i++;
        while (mp[a[j]] > fr) j--;
        if (i <= j) swap(a[i++], a[j--]);
      }
      if (k <= j) r = j;
      else if (k >= i) l = i;
      else break;
    }

    return vector<int>{a.begin() + k, a.end()};
  }
};
// @lc code=end
