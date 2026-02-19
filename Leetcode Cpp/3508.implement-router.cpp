/*
 * @lc app=leetcode id=3508 lang=cpp
 *
 * [3508] Implement Router
 */

// @lc code=start
class Router {
  struct Packet {
    int source, destination, timestamp;
    bool operator==(const Packet &other) const {
      return source == other.source && destination == other.destination &&
             timestamp == other.timestamp;
    }
  };

  struct PacketHash {
    size_t operator()(const Packet &p) const {
      using ll = long long;
      return hash<ll>{}((ll)p.source << 40 | (ll)p.destination << 20 |
                        (ll)p.timestamp);
    }
  };

  unordered_set<Packet, PacketHash> seen;
  queue<Packet> q;
  // destination -> timestamps
  unordered_map<int, deque<int>> mp;
  int limit;

public:
  Router(int memoryLimit) : limit(memoryLimit) {}

  bool addPacket(int source, int destination, int timestamp) {
    auto pkt = Packet{
        .source = source, .destination = destination, .timestamp = timestamp};
    if (!seen.insert(pkt).second)
      return false;
    if (q.size() == limit) {
      seen.erase(q.front());
      mp[q.front().destination].pop_front();
      q.pop();
    }
    q.push(pkt);
    mp[destination].push_back(timestamp);
    return true;
  }

  vector<int> forwardPacket() {
    if (q.empty())
      return {};
    auto pkt = q.front();
    q.pop();
    seen.erase(pkt);
    mp[pkt.destination].pop_front();
    return {pkt.source, pkt.destination, pkt.timestamp};
  }

  int getCount(int destination, int startTime, int endTime) {
    auto &dq = mp[destination];
    return upper_bound(dq.begin(), dq.end(), endTime) -
           lower_bound(dq.begin(), dq.end(), startTime);
  }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
// @lc code=end
