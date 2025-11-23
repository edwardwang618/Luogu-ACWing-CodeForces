/*
 * @lc app=leetcode id=1224 lang=cpp
 *
 * [1224] Maximum Equal Frequency
 */

// @lc code=start
class Solution {
 public:
#define x first
#define y second
  int maxEqualFreq(vector<int>& nums) {
    unordered_map<int, int> cnt, mp;
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      int x = nums[i];
      if (cnt.count(x)) {
        mp[cnt[x]]--;
        if (!mp[cnt[x]]) mp.erase(cnt[x]);
      }

      cnt[x]++;
      mp[cnt[x]]++;

      if (mp.size() == 1) {
        for (auto& [k, v] : mp)
          if (k == 1 || v == 1) res = i + 1;
      } else if (mp.size() == 2) {
        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end());
        if (v[0].x == 1 && v[0].y == 1 || v[0].x + 1 == v[1].x && v[1].y == 1)
          res = i + 1;
      }
    }

    return res;
  }
};
// @lc code=end
