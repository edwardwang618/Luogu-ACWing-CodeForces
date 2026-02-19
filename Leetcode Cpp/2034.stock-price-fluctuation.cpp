/*
 * @lc app=leetcode id=2034 lang=cpp
 *
 * [2034] Stock Price Fluctuation
 */

// @lc code=start
class StockPrice {
  map<int, int> prices;
  unordered_map<int, int> mp;
  int maxTimestamp = 0;

public:
  StockPrice() {}

  void update(int timestamp, int price) {
    if (auto [it, ins] = mp.emplace(timestamp, price); !ins) {
      int oldPrice = it->second;
      if (auto priceIt = prices.find(oldPrice); priceIt->second == 1)
        prices.erase(priceIt);
      else
        priceIt->second--;
      it->second = price;
    }
    prices[price]++;
    maxTimestamp = max(maxTimestamp, timestamp);
  }

  int current() { return mp[maxTimestamp]; }

  int maximum() { return prices.rbegin()->first; }

  int minimum() { return prices.begin()->first; }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end
