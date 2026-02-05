/*
 * @lc app=leetcode id=588 lang=cpp
 *
 * [588] Design In-Memory File System
 */

// @lc code=start
class FileSystem {
public:
  struct Dir {
    unordered_map<string, int> dirs;
    unordered_map<string, string> files;
  };

  vector<Dir> pool;
  const int root;
#define dirs(f) pool[f].dirs
#define files(f) pool[f].files

  FileSystem() : root(0) { pool.emplace_back(); }

  int new_dir() {
    int n = pool.size();
    pool.emplace_back();
    return n;
  }

  vector<string> ls(const string &path) {
    int f = root;
    string fname;
    int pn = path.size();
    for (int i = 1; i < pn; i++) {
      int j = i;
      while (j < pn && path[j] != '/')
        j++;
      fname = path.substr(i, j - i);
      if (j == pn)
        break;
      f = dirs(f)[fname];
      i = j;
    }

    if (fname.size()) {
      if (files(f).count(fname))
        return {fname};
      f = dirs(f)[fname];
    }
    vector<string> res;
    for (auto &[k, v] : dirs(f))
      res.push_back(k);
    for (auto &[k, v] : files(f))
      res.push_back(k);
    sort(res.begin(), res.end());
    return res;
  }

  void mkdir(const string &path) {
    int f = root;
    int pn = path.size();
    for (int i = 1; i < pn; i++) {
      int j = i;
      while (j < pn && path[j] != '/')
        j++;
      auto fname = path.substr(i, j - i);
      int &nf = dirs(f)[fname];
      if (!nf)
        nf = new_dir();
      f = nf;
      i = j;
    }
  }

  void addContentToFile(const string &path, const string &content) {
    int f = root;
    string fname;
    int pn = path.size();
    for (int i = 1; i < pn; i++) {
      int j = i;
      while (j < pn && path[j] != '/')
        j++;
      fname = path.substr(i, j - i);
      if (j == pn)
        break;
      f = dirs(f)[fname];
      i = j;
    }
    files(f)[fname] += content;
  }

  string readContentFromFile(const string &path) {
    int f = root;
    string fname;
    int pn = path.size();
    for (int i = 1; i < pn; i++) {
      int j = i;
      while (j < pn && path[j] != '/')
        j++;
      fname = path.substr(i, j - i);
      if (j == pn)
        break;
      f = dirs(f)[fname];
      i = j;
    }
    return files(f)[fname];
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
