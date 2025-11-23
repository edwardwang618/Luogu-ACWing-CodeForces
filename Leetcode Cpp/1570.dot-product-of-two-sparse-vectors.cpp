/*
 * @lc app=leetcode id=1570 lang=cpp
 *
 * [1570] Dot Product of Two Sparse Vectors
 */

// @lc code=start
class SparseVector {
 public:
  unordered_map<int, int> v;

  SparseVector(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++)
      if (nums[i]) v[i] = nums[i];
  }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    auto v2 = vec.v;
    int res = 0;
    for (auto& [k, n] : v)
      if (v2.count(k)) res += n * v2[k];

    return res;
  }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
// @lc code=end
