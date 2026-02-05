/*
 * @lc app=leetcode id=1797 lang=cpp
 *
 * [1797] Design Authentication Manager
 */

// @lc code=start
class AuthenticationManager {
  int timeToLive;
  unordered_map<string, int> mp;

public:
  AuthenticationManager(int timeToLive) : timeToLive(timeToLive) {}

  void generate(const string &tokenId, int currentTime) {
    mp[tokenId] = currentTime + timeToLive;
  }

  void renew(const string &tokenId, int currentTime) {
    auto it = mp.find(tokenId);
    if (it == mp.end())
      return;
    if (it->second <= currentTime)
      return;
    it->second = currentTime + timeToLive;
  }

  int countUnexpiredTokens(int currentTime) {
    for (auto it = mp.begin(); it != mp.end();)
      if (it->second <= currentTime)
        it = mp.erase(it);
      else
        ++it;
    return mp.size();
  }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
// @lc code=end
