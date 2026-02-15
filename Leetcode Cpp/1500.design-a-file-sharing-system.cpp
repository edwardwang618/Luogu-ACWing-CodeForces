/*
 * @lc app=leetcode id=1500 lang=cpp
 *
 * [1500] Design a File Sharing System
 */

// @lc code=start
class FileSharing {
  int m;
  priority_queue<int, vector<int>, greater<>> availableIds;
  unordered_map<int, unordered_set<int>> userChunks;
  unordered_map<int, set<int>> chunkUsers;
  int nextId = 1;

public:
  FileSharing(int m) : m(m) {}

  int join(const vector<int> &ownedChunks) {
    int id;
    if (availableIds.empty())
      id = nextId++;
    else {
      id = availableIds.top();
      availableIds.pop();
    }

    for (int c : ownedChunks) {
      userChunks[id].insert(c);
      chunkUsers[c].insert(id);
    }
    return id;
  }

  void leave(int userID) {
    for (int c : userChunks[userID])
      chunkUsers[c].erase(userID);
    userChunks.erase(userID);
    availableIds.push(userID);
  }

  vector<int> request(int userID, int chunkID) {
    auto &users = chunkUsers[chunkID];
    vector<int> res(users.begin(), users.end());
    if (res.size()) {
      userChunks[userID].insert(chunkID);
      chunkUsers[chunkID].insert(userID);
    }
    return res;
  }
};

/**
 * Your FileSharing object will be instantiated and called as such:
 * FileSharing* obj = new FileSharing(m);
 * int param_1 = obj->join(ownedChunks);
 * obj->leave(userID);
 * vector<int> param_3 = obj->request(userID,chunkID);
 */
// @lc code=end
