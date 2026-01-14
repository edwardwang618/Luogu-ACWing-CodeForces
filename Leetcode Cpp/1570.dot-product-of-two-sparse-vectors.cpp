/*
 * @lc app=leetcode id=1570 lang=cpp
 *
 * [1570] Dot Product of Two Sparse Vectors
 */

// @lc code=start
class SparseVector {
 public:
 using PII = pair<int, int>;
  vector<PII> v;

  SparseVector(vector<int>& a) {
    for (int i = 0; i < a.size(); i++)
      if (a[i]) v.emplace_back(i, a[i]);
  }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    auto &v2 = vec.v;
    int res = 0;
    for (int i = 0, j = 0; i < v.size() && j < vec.v.size(); ) {
      if (v[i].first < v2[j].first) i++;
      else if (v[i].first > v2[j].first) j++;
      else {
        res += v[i].second * v2[j].second;
        i++;
        j++;
      }
    }
    return res;
  }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
// @lc code=end
