/*
 * @lc app=leetcode id=1865 lang=cpp
 *
 * [1865] Finding Pairs With a Certain Sum
 */

// @lc code=start
class FindSumPairs {
public:
  vector<int> a, b;
  unordered_map<int, int> mpb;

  FindSumPairs(vector<int> &a, vector<int> &b) : a(move(a)), b(move(b)) {
    for (int x : this->b)
      mpb[x]++;
  }

  void add(int idx, int x) {
    auto it = mpb.find(b[idx]);
    if (it->second == 1)
      mpb.erase(it);
    else
      --it->second;

    b[idx] += x;
    mpb[b[idx]]++;
  }

  int count(int tot) {
    int res = 0;
    for (int x : a) {
      if (auto it = mpb.find(tot - x); it != mpb.end())
        res += it->second;
    }
    return res;
  }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
// @lc code=end
