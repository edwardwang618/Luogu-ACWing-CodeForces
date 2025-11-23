/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
class NumArray {
 public:
#define lowbit(x) (x & -x)
  int n;
  vector<int> tr, A;

  void add(int k, int x) {
    for (; k <= n; k += lowbit(k)) tr[k] += x;
  }

  int sum(int k) {
    int res = 0;
    for (; k; k -= lowbit(k)) res += tr[k];
    return res;
  }

  NumArray(vector<int>& nums) {
    A.swap(nums);
    n = A.size();
    tr.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      tr[i] += A[i - 1];
      int j = i + lowbit(i);
      if (j <= n) tr[j] += tr[i];
    }
  }

  void update(int i, int val) {
    add(i + 1, val - A[i]);
    A[i] = val;
  }

  int sumRange(int l, int r) { return sum(r + 1) - sum(l); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
