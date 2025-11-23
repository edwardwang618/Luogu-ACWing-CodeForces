/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& a, int k) {
    unordered_map<int, int> mp;
    for (int x : a) mp[x]++;
    vector<int> v;
    for (auto& [key, freq] : mp) v.push_back(key);
    quick_select(0, v.size() - 1, v.size() - k, v, mp);
    return vector<int>(v.begin() + v.size() - k, v.end());
  }

  void quick_select(int l, int r, int k, vector<int>& v, auto& mp) {
    while (l < r) {
      int i = l, j = r;
      int piv_freq = mp[v[i + (j - i >> 1)]];
      while (i <= j) {
        while (mp[v[i]] < piv_freq) i++;
        while (mp[v[j]] > piv_freq) j--;
        if (i <= j) swap(v[i++], v[j--]);
      }

      if (k <= j) r = j;
      else if (k >= i) l = i;
      else break;
    }
  }
};
// @lc code=end
