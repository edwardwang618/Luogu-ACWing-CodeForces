/*
 * @lc app=leetcode id=2080 lang=cpp
 *
 * [2080] Range Frequency Queries
 */

// @lc code=start
class RangeFreqQuery {
public:
  unordered_map<int, vector<int>> mp;

  RangeFreqQuery(vector<int> &a) {
    for (int i = 0; i < a.size(); ++i)
      mp[a[i]].push_back(i);
  }

  int query(int l, int r, int x) {
    if (auto it = mp.find(x); it != mp.end()) {
      auto &v = it->second;
      return upper_bound(v.begin(), v.end(), r) -
             lower_bound(v.begin(), v.end(), l);
    }
    return 0;
  }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,val);
 */
// @lc code=end
