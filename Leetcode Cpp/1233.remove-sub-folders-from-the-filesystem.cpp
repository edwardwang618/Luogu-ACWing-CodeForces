/*
 * @lc app=leetcode id=1233 lang=cpp
 *
 * [1233] Remove Sub-Folders from the Filesystem
 */

// @lc code=start
class Solution {
public:
  vector<string> removeSubfolders(vector<string> &fs) {
    sort(fs.begin(), fs.end());
    vector<string> res;
    string p;
    for (auto &f : fs) {
      if (p.empty())
        p = f;
      else if (f.size() > p.size() && !f.compare(0, p.size(), p) &&
               f[p.size()] == '/')
        continue;
      res.push_back(f);
      p = f;
    }
    return res;
  }
};
// @lc code=end
