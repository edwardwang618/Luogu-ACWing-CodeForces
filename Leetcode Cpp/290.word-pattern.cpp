/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {
 public:
  bool wordPattern(string p, string s) {
    stringstream ss(s);
    vector<string> v;
    {
      string w;
      while (ss >> w) v.push_back(w);
    }
    if (v.size() != p.size()) return false;
    unordered_map<char, int> mp1;
    unordered_map<string, int> mp2;
    for (int i = 0; i < p.size(); i++)
      if (!mp1.count(p[i]) && !mp2.count(v[i]))
        mp1[p[i]] = mp2[v[i]] = i;
      else if (mp1.count(p[i]) ^ mp2.count(v[i]))
        return false;
      else if (mp1[p[i]] != mp2[v[i]])
        return false;

    return true;
  }
};
// @lc code=end
