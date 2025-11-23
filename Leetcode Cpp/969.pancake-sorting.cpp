/*
 * @lc app=leetcode id=969 lang=cpp
 *
 * [969] Pancake Sorting
 */

// @lc code=start
class Solution {
 public:
  vector<int> pancakeSort(vector<int>& A) {
    int n = A.size();
    vector<int> res;
    for (int i = n - 1; i; i--) {
      int pos = i;
      for (int j = 0; j < i; j++)
        if (A[j] > A[pos]) pos = j;
    
      if (pos == i) continue;
      reverse(A.begin(), A.begin() + pos + 1);
      res.push_back(pos + 1);
      reverse(A.begin(), A.begin() + i + 1);
      res.push_back(i + 1);
    }

    return res;
  }
};
// @lc code=end
