/*
 * @lc app=leetcode id=2251 lang=cpp
 *
 * [2251] Number of Flowers in Full Bloom
 */

// @lc code=start
class Solution {
public:
#if 0
  vector<int> fullBloomFlowers(vector<vector<int>> &fs, vector<int> &p) {
    int n = p.size();
    vector<int> starts(n), ends(n);
    for (auto &f : fs) starts.push_back(f[0]), ends.push_back(f[1]);
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    vector<int> res(n);
    for (int i = 0; i < p.size(); i++) {
      int x = p[i];
      int open = upper_bound(starts.begin(), starts.end(), x) - starts.begin();
      int close = lower_bound(ends.begin(), ends.end(), x) - ends.begin();
      res[i] = open - close;
    }
    return res;
  }
#endif

  vector<int> fullBloomFlowers(vector<vector<int>> &fs, vector<int> &p) {
    int n = p.size();
    map<int, int> mp;
    for (auto &f : fs) {
      mp[f[0]]++;
      mp[f[1] + 1]--;
    }

    vector<int> res(n);
    using PII = pair<int, int>;
    vector<PII> qs(n);
    for (int i = 0; i < n; i++) qs[i] = {p[i], i};
    sort(qs.begin(), qs.end());
    int cnt = 0;
    auto it = mp.begin();
    for (auto &[x, idx] : qs) {
      while (it != mp.end() && it->first <= x) {
        cnt += it->second;
        ++it;
      }
      res[idx] = cnt;
    }
    return res;
  }
};
// @lc code=end
