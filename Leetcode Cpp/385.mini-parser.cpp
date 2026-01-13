/*
 * @lc app=leetcode id=385 lang=cpp
 *
 * [385] Mini Parser
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer
 * to it. void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
  NestedInteger deserialize(string &s) {
    int idx = 0, n = s.size();
    auto parse_int = [&]() {
      int sign = 1;
      if (s[idx] == '-') {
        sign = -1;
        idx++;
      }
      int x = 0;
      while (idx < n && isdigit(s[idx])) {
        x = x * 10 + s[idx] - '0';
        idx++;
      }
      return sign * x;
    };
    auto dfs = [&](this auto &&dfs) -> NestedInteger {
      if (s[idx] == '[') {
        idx++;
        NestedInteger res;
        while (s[idx] != ']') {
          res.add(dfs());
          if (s[idx] == ',')
            idx++;
        }
        idx++;
        return res;
      }
      return NestedInteger(parse_int());
    };
    return dfs();
  }
};
// @lc code=end
