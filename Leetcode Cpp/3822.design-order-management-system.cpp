/*
 * @lc app=leetcode id=3822 lang=cpp
 *
 * [3822] Design Order Management System
 */

// @lc code=start
class OrderManagementSystem {
public:
  struct Order {
    enum class Type { BUY, SELL };
    Type type;
    int price;
  };

  unordered_map<int, Order> orders;
  unordered_map<int, unordered_set<int>> buyOrders, sellOrders;

  auto &getMap(Order::Type type) {
    return type == Order::Type::BUY ? buyOrders : sellOrders;
  }

  OrderManagementSystem() {}

  void addOrder(int orderId, const string &orderType, int price) {
    Order order{.type =
                    orderType[0] == 'b' ? Order::Type::BUY : Order::Type::SELL,
                .price = price};
    orders[orderId] = order;
    getMap(order.type)[price].insert(orderId);
  }

  void modifyOrder(int orderId, int newPrice) {
    auto &order = orders[orderId];
    getMap(order.type)[order.price].erase(orderId);
    getMap(order.type)[newPrice].insert(orderId);
    order.price = newPrice;
  }

  void cancelOrder(int orderId) {
    auto it = orders.find(orderId);
    getMap(it->second.type)[it->second.price].erase(orderId);
    orders.erase(orderId);
  }

  vector<int> getOrdersAtPrice(const string &orderType, int price) {
    auto &st = getMap(orderType[0] == 'b' ? Order::Type::BUY
                                          : Order::Type::SELL)[price];
    return vector<int>(st.begin(), st.end());
  }
};

/**
 * Your OrderManagementSystem object will be instantiated and called as such:
 * OrderManagementSystem* obj = new OrderManagementSystem();
 * obj->addOrder(orderId,orderType,price);
 * obj->modifyOrder(orderId,newPrice);
 * obj->cancelOrder(orderId);
 * vector<int> param_4 = obj->getOrdersAtPrice(orderType,price);
 */
// @lc code=end
