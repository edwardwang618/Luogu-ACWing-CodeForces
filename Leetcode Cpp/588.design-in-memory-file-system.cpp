/*
 * @lc app=leetcode id=588 lang=cpp
 *
 * [588] Design In-Memory File System
 */

// @lc code=start
class FileSystem {
 public:
  struct Dir {
    unordered_map<string, Dir *> dirs;
    unordered_map<string, string> files;
  };

  Dir *root;

  FileSystem() { root = new Dir(); }

  vector<string> ls(string path) {
    auto *f = root;
    string fname;
    for (int i = 1; i < path.size(); i++) {
      int j = i;
      while (j < path.size() && path[j] != '/') j++;
      fname = path.substr(i, j - i);
      if (j == path.size()) break;
      f = f->dirs[fname];
      i = j;
    }

    if (fname.size()) {
      if (f->files.count(fname)) return {fname};
      f = f->dirs[fname];
    }
    vector<string> res;
    for (auto &[k, v] : f->dirs) res.push_back(k);
    for (auto &[k, v] : f->files) res.push_back(k);
    sort(res.begin(), res.end());
    return res;
  }

  void mkdir(string path) {
    auto *f = root;
    for (int i = 1; i < path.size(); i++) {
      int j = i;
      while (j < path.size() && path[j] != '/') j++;
      auto fname = path.substr(i, j - i);
      if (!f->dirs.count(fname)) f->dirs[fname] = new Dir();
      f = f->dirs[fname];
      i = j;
    }
  }

  void addContentToFile(string path, string content) {
    auto *f = root;
    string fname;
    for (int i = 1; i < path.size(); i++) {
      int j = i;
      while (j < path.size() && path[j] != '/') j++;
      fname = path.substr(i, j - i);
      if (j == path.size()) break;
      f = f->dirs[fname];
      i = j;
    }
    f->files[fname] += content;
  }

  string readContentFromFile(string path) {
    auto *f = root;
    string fname;
    for (int i = 1; i < path.size(); i++) {
      int j = i;
      while (j < path.size() && path[j] != '/') j++;
      fname = path.substr(i, j - i);
      if (j == path.size()) break;
      f = f->dirs[fname];
      i = j;
    }
    return f->files[fname];
  }
};
/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
// @lc code=end
