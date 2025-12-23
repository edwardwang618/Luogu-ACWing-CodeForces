/*
 * @lc app=leetcode id=770 lang=cpp
 *
 * [770] Basic Calculator IV
 */

// @lc code=start
class Solution {
public:
  struct Item {
    // coefficient
    int c;
    multiset<string> vars;
    Item(int c, const multiset<string>& vars): c(c), vars(vars) {}
    Item(int c, multiset<string>&& vars = {}): c(c), vars(std::move(vars)) {}
    bool operator<(const Item &t) const {
      if (vars.size() != t.vars.size())
        return vars.size() > t.vars.size();
      return vars < t.vars;
    }
    string convert_to_string() {
      string res = to_string(c);
      for (auto &v : vars)
        res += "*" + v;
      return res;
    }
  };
  vector<string> basicCalculatorIV(string &s, vector<string> &evs,
                                   vector<int> &eval) {
    unordered_map<string, int> val_to_int;
    for (int i = 0; i < evs.size(); i++) val_to_int[evs[i]] = eval[i];
    stack<vector<Item>> stk;
    stack<char> ops;
    auto add = [](auto &a, auto &b, int sign) {
      vector<Item> res;
      int i, j;
      for (i = 0, j = 0; i < a.size() && j < b.size();) {
        if (a[i] < b[j])
          res.push_back(a[i++]);
        else if (b[j] < a[i]) {
          res.emplace_back(sign * b[j].c, b[j].vars);
          j++;
        } else {
          int c = a[i].c + sign * b[j].c;
          if (c) res.emplace_back(c, a[i].vars);
          i++, j++;
        }
      }
      while (i < a.size())
        res.push_back(a[i++]);
      while (j < b.size()) {
        res.emplace_back(sign * b[j].c, b[j].vars);
        j++;
      }
      return res;
    };
    auto mult = [&](auto &a, auto &b) {
      vector<Item> res;
      auto merge = [&](auto &s1, auto &s2) {
        multiset<string> res;
        for (auto &x : s1)
          res.insert(x);
        for (auto &x : s2)
          res.insert(x);
        return res;
      };
      for (auto &x : a) {
        vector<Item> items;
        for (auto &y : b)
          items.emplace_back(x.c * y.c, merge(x.vars, y.vars));
        res = add(res, items, 1);
      }
      return res;
    };
    auto pr = [](char op) {
      switch (op) {
        case '+': case '-': return 0;
        case '*': return 1;
      }
      return -1;
    };
    auto calc = [&](auto &stk, auto &ops) {
      auto b = stk.top(); stk.pop();
      auto a = stk.top(); stk.pop();
      char op = ops.top(); ops.pop();
      switch (op) {
        case '+': stk.push(add(a, b, 1)); break;
        case '-': stk.push(add(a, b, -1)); break;
        case '*': stk.push(mult(a, b));
      }
    };

    int n = s.size();
    for (int i = 0; i < n; i++) {
      char ch = s[i];
      if (ch == ' ') continue;
      if (isalnum(ch)) {
        vector<Item> items;
        if (isdigit(ch)) {
          int j = i, x = 0;
          while (j < n && isdigit(s[j]))
            x = x * 10 + s[j++] - '0';
          i = j - 1;
          if (x) items.emplace_back(x);
        } else {
          int j = i;
          string var;
          while (j < n && isalpha(s[j])) var += s[j++];
          i = j - 1;
          if (auto it = val_to_int.find(var); it != val_to_int.end()) {
            if (it->second) items.emplace_back(it->second);
          } else items.emplace_back(1, multiset<string>{var});
        }
        stk.push(items);
      } else if (ch == '(') ops.push(ch);
      else if (ch == ')') {
        while (ops.top() != '(') calc(stk, ops);
        ops.pop();
      } else {
        while (ops.size() && ops.top() != '(' && pr(ops.top()) >= pr(ch))
          calc(stk, ops);
        ops.push(ch);
      }
    }
    while (ops.size()) calc(stk, ops);
    vector<string> res;
    for (auto &item : stk.top()) 
      res.push_back(item.convert_to_string());
    return res;
  }
};
// @lc code=end
