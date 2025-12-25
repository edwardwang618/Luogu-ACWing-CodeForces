/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray {
public:
  vector<int> s;
  NumArray(vector<int> &a) {
    int n = a.size();
    s.resize(n + 1);
    for (int i = 0; i < n; i++)
      s[i + 1] = s[i] + a[i];
  }

  int sumRange(int l, int r) { return s[r + 1] - s[l]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
