/*
 * @lc app=leetcode id=1507 lang=cpp
 *
 * [1507] Reformat Date
 */

// @lc code=start
class Solution {
 public:
  string reformatDate(string date) {
    unordered_map<string, string> mp{
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
        {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
        {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
    string d, m, y;
    istringstream iss(date);
    iss >> d >> m >> y;
    if (isdigit(d[1])) d = d.substr(0, 2);
    else d = "0" + d.substr(0, 1);
    return y + "-" + mp[m] + "-" + d;
  }
};
// @lc code=end
