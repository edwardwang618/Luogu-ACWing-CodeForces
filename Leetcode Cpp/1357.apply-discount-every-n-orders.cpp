/*
 * @lc app=leetcode id=1357 lang=cpp
 *
 * [1357] Apply Discount Every n Orders
 */

// @lc code=start
class Cashier {
  int n, discount, cnt = 0;
  unordered_map<int, int> mp;

public:
  Cashier(int n, int discount, vector<int> &products, vector<int> &prices)
      : n(n), discount(discount) {
    for (int i = 0; i < products.size(); i++)
      mp[products[i]] = prices[i];
  }

  double getBill(const vector<int> &product, const vector<int> &amount) {
    double sum = 0;
    for (int i = 0; i < product.size(); i++)
      sum += mp[product[i]] * amount[i];
    cnt++;
    if (cnt == n) {
      cnt = 0;
      sum *= (100.0 - discount) / 100;
    }
    return sum;
  }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
// @lc code=end
