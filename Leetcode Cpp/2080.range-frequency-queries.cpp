/*
 * @lc app=leetcode id=2080 lang=cpp
 *
 * [2080] Range Frequency Queries
 */

// @lc code=start
class RangeFreqQuery {
 public:
  unordered_map<int, vector<int>> mp;

  RangeFreqQuery(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) mp[arr[i]].push_back(i);
  }

  int query(int left, int right, int val) {
    auto& v = mp[val];
    return upper_bound(v.begin(), v.end(), right) -
           lower_bound(v.begin(), v.end(), left);
  }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,val);
 */
// @lc code=end
