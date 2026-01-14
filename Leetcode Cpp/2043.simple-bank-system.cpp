/*
 * @lc app=leetcode id=2043 lang=cpp
 *
 * [2043] Simple Bank System
 */

// @lc code=start
class Bank {
public:
  using ll = long long;
  vector<ll> &b;
  Bank(vector<ll> &balance) : b(balance) {}

  bool check(int a) { return 1 <= a && a <= b.size(); }

  bool transfer(int a1, int a2, ll money) {
    if (!check(a1) || !check(a2))
      return false;
    if (b[a1 - 1] < money) return false;
    b[a1 - 1] -= money;
    b[a2 - 1] += money;
    return true;
  }

  bool deposit(int a, ll money) {
    if (!check(a)) return false;
    b[a - 1] += money;
    return true;
  }

  bool withdraw(int a, ll money) {
    if (!check(a)) return false;
    if (b[a - 1] < money) return false;
    b[a - 1] -= money;
    return true;
  }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
// @lc code=end
