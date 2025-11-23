/*
 * @lc app=leetcode id=1090 lang=cpp
 *
 * [1090] Largest Values From Labels
 */

// @lc code=start
class Solution {
 public:
  using PII = pair<int, int>;
  int largestValsFromLabels(vector<int>& vs, vector<int>& ls, int numW,
                            int useL) {
    vector<int> idx;
    for (int i = 0; i < vs.size(); i++) idx.push_back(i);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return vs[i] > vs[j]; });

    unordered_map<int, int> mp;
    int res = 0, cnt = 0;
    for (int id : idx) {
      int l = ls[id], v = vs[id];
      if (mp[l] + 1 <= useL && cnt + 1 <= numW) {
        res += v;
        if (cnt + 1 == numW) break;
        cnt++;
        mp[l]++;
      }
    }

    return res;
  }
};
// @lc code=end
