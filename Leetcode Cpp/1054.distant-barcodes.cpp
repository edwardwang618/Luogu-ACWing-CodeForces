/*
 * @lc app=leetcode id=1054 lang=cpp
 *
 * [1054] Distant Barcodes
 */

// @lc code=start
class Solution {
 public:
  using PII = pair<int, int>;
  vector<int> rearrangeBarcodes(vector<int> &bs) {
    unordered_map<int, int> mp;
    for (int x : bs) mp[x]++;
    vector<PII> v;
    for (auto &[k, c] : mp) v.push_back({c, k});
    sort(v.begin(), v.end(), greater<PII>());
    int idx = 0;
    for (auto &p : v)
      for (int i = 0; i < p.first; i++) {
        bs[idx] = p.second;
        idx += 2;
        if (idx >= bs.size()) idx = 1;
      }

    return bs;
  }
};
// @lc code=end
