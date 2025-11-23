/*
 * @lc app=leetcode id=1166 lang=cpp
 *
 * [1166] Design File System
 */

// @lc code=start
class FileSystem {
 public:
  unordered_map<string, int> mp;
  FileSystem() {}

  bool createPath(string path, int value) {
    if (mp.count(path)) return false;
    int idx = path.size() - 1;
    while (path[idx] != '/') idx--;
    string parent = path.substr(0, idx);
    if (idx && !mp.count(parent)) return false;
    mp[path] = value;
    return true;
  }

  int get(string path) {
    auto it = mp.find(path);
    return it == mp.end() ? -1 : it->second;
  }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
// @lc code=end
