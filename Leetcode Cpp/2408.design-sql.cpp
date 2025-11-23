/*
 * @lc app=leetcode id=2408 lang=cpp
 *
 * [2408] Design SQL
 */

// @lc code=start
class SQL {
 private:
  unordered_map<string, unordered_map<int, vector<string>>> mp;
  unordered_map<string, int> ids;

 public:
  SQL(vector<string>& names, vector<int>& columns) {}

  void insertRow(string name, vector<string> row) {
    mp[name][++ids[name]] = row;
  }

  void deleteRow(string name, int rowId) { mp[name].erase(rowId); }

  string selectCell(string name, int rowId, int columnId) {
    return mp[name][rowId][columnId - 1];
  }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * obj->insertRow(name,row);
 * obj->deleteRow(name,rowId);
 * string param_3 = obj->selectCell(name,rowId,columnId);
 */
// @lc code=end
