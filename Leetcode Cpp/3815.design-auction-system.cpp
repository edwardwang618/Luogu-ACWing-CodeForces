/*
 * @lc app=leetcode id=3815 lang=cpp
 *
 * [3815] Design Auction System
 */

// @lc code=start
class AuctionSystem {
  // itemId -> userId -> bidAmount
  unordered_map<int, unordered_map<int, int>> bids;
  using PII = pair<int, int>;
  // itemId -> <bidAmount, userId>
  unordered_map<int, set<PII, greater<>>> mp;

public:
  AuctionSystem() {}

  void addBid(int userId, int itemId, int bidAmount) {
    auto &st = bids[itemId];
    if (st.find(userId) != st.end()) {
      updateBid(userId, itemId, bidAmount);
      return;
    }
    bids[itemId][userId] = bidAmount;
    mp[itemId].emplace(bidAmount, userId);
  }

  void updateBid(int userId, int itemId, int newAmount) {
    int &oldAmount = bids[itemId][userId];
    auto &st = mp[itemId];
    st.erase(make_pair(oldAmount, userId));
    st.emplace(newAmount, userId);
    oldAmount = newAmount;
  }

  void removeBid(int userId, int itemId) {
    int amount = bids[itemId][userId];
    bids[itemId].erase(userId);
    mp[itemId].erase(make_pair(amount, userId));
  }

  int getHighestBidder(int itemId) {
    auto &st = mp[itemId];
    if (st.empty())
      return -1;
    return st.begin()->second;
  }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */
// @lc code=end
