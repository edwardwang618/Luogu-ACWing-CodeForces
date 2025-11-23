/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */

// @lc code=start
class Solution {
 public:
  bool isValidSerialization(string t) {
    istringstream ss(t);
    vector<string> v;
    for (string s; getline(ss, s, ',');) v.push_back(s);
    int idx = 0;
    return dfs(idx, v) && idx == v.size();
  }

  bool dfs(int &idx, vector<string> &v) {
    if (idx == v.size()) return false;
    if (v[idx] == "#") {
      idx++;
      return true;
    }

    idx++;
    return dfs(idx, v) && dfs(idx, v);
  }
};
// @lc code=end
