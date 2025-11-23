/*
 * @lc app=leetcode id=1554 lang=cpp
 *
 * [1554] Strings Differ by One Character
 */

// @lc code=start
class Solution {
 public:
  using UL = unsigned long;
  bool differByOne(vector<string>& dict) {
    UL P = 131;
    if (dict.empty()) return false;
    int n = dict[0].size();
    UL pow[n];
    memset(pow, 0, sizeof pow);
    pow[0] = 1;
    for (int i = 1; i < n; i++) pow[i] = pow[i - 1] * P;
    vector<UL> ha;
    for (int i = 0; i < dict.size(); i++) {
      UL hash = 0;
      for (int j = 0; j < n; j++) hash = hash * P + dict[i][j];
      ha.push_back(hash);
    }

    unordered_set<UL> st;
    for (int i = 0; i < dict.size(); i++) {
      UL hash = ha[i];
      vector<UL> v;
      for (int j = 0; j < n; j++) {
        UL new_ha = hash - pow[n - 1 - j] * dict[i][j];
        if (st.count(new_ha)) return true;
        v.push_back(new_ha);
      }

      st.insert(v.begin(), v.end());
    }

    return false;
  }
};
// @lc code=end
