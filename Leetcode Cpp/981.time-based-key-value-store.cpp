/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap {
public:
  using PIS = pair<int, string>;
  unordered_map<string, vector<PIS>> mp;

  TimeMap() {}

  void set(const string &key, const string &val, int timestamp) {
    mp[key].emplace_back(timestamp, val);
  }

  string get(const string &key, int timestamp) {
    auto it = mp.find(key);
    if (it == mp.end()) return "";
    auto &v = it->second;
    auto it_key = upper_bound(v.begin(), v.end(), timestamp, [](int t, auto &p) {
      return t < p.first;
    });
    return it_key == v.begin() ? "" : prev(it_key)->second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
