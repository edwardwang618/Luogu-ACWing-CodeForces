/*
 * @lc app=leetcode id=2241 lang=cpp
 *
 * [2241] Design an ATM Machine
 */

// @lc code=start
class ATM {
public:
  static constexpr int a[]{20, 50, 100, 200, 500};
  static constexpr int n = sizeof(a) / sizeof(int);
  vector<int> cnt;
  ATM() : cnt(n) {}

  void deposit(vector<int> banknotesCount) {
    for (int i = 0; i < n; i++)
      cnt[i] += banknotesCount[i];
  }

  vector<int> withdraw(int k) {
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--) {
      res[i] = min(k / a[i], cnt[i]);
      k -= a[i] * res[i];
      if (!k) {
        for (int i = 0; i < n; i++)
          cnt[i] -= res[i];
        return res;
      }
    }

    return {-1};
  }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
// @lc code=end
