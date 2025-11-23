/*
 * @lc app=leetcode id=635 lang=cpp
 *
 * [635] Design Log Storage System
 */

// @lc code=start
class LogSystem {
 public:
  multimap<string, int> mp;
  map<string, int> len{{"Year", 5},  {"Month", 8},   {"Day", 11},
                       {"Hour", 14}, {"Minute", 17}, {"Second", 19}};
  string first = "0000:00:00:00:00:00";
  string last = "9999:12:31:23:59:59";

  LogSystem() {}

  void put(int id, string timestamp) { mp.insert({timestamp, id}); }

  vector<int> retrieve(string st, string ed, string gran) {
    vector<int> res;
    int idx = len[gran];
    string l = st.substr(0, idx) + first.substr(idx),
           r = ed.substr(0, idx) + last.substr(idx);
    auto low = mp.lower_bound(l), up = mp.upper_bound(r);
    for (auto it = low; it != up; ++it) res.push_back(it->second);
    return res;
  }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */
// @lc code=end
