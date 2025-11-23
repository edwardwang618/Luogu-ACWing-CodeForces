/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

// @lc code=start
class Solution {
 public:
  vector<vector<string>> suggestedProducts(vector<string>& ps, string w) {
    vector<vector<string>> res;
    sort(ps.begin(), ps.end());
    string sub;
    for (int i = 0, k = 0; i < w.size(); i++) {
      sub += w[i];
      while (k < ps.size() && ps[k] < sub) k++;
      if (k == ps.size())
        res.push_back({});
      else {
        vector<string> v;
        for (int j = k; j < k + 3 && j < ps.size(); j++)
          if (ps[j].substr(0, sub.size()) == sub) v.push_back(ps[j]);
        res.push_back(v);
      }
    }

    return res;
  }
};
// @lc code=end
