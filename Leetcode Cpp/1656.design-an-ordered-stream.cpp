/*
 * @lc app=leetcode id=1656 lang=cpp
 *
 * [1656] Design an Ordered Stream
 */

// @lc code=start
class OrderedStream {
public:
  vector<string> v;
  int idx;

  OrderedStream(int n) {
    v.resize(n);
    idx = 0;
  }

  vector<string> insert(int id, const string &s) {
    vector<string> res;
    v[id - 1] = s;
    while (idx < v.size() && v[idx].size())
      res.push_back(v[idx++]);
    return res;
  }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
// @lc code=end
