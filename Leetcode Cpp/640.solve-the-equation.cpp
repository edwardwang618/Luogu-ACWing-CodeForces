/*
 * @lc app=leetcode id=640 lang=cpp
 *
 * [640] Solve the Equation
 */

// @lc code=start
class Solution {
public:
  string solveEquation(string &e) {
    auto parse = [&](string &s) {
      s = s + "+";
      int coeff = 0, cons = 0;
      int sign = 1, x = 0;
      bool hasNum = false;
      for (char ch : s) {
        if (isdigit(ch)) {
          x = x * 10 + ch - '0';
          hasNum = true;
        } else if (ch == 'x') {
          coeff += sign * (hasNum ? x : 1);
          x = 0;
          hasNum = false;
        } else {
          if (hasNum) cons += sign * x;
          x = 0;
          hasNum = false;
          sign = ch == '-' ? -1 : 1;
        }
      }
      return make_pair(coeff, cons);
    };
    istringstream iss(e);
    string s;
    vector<string> v;
    while (getline(iss, s, '=')) v.push_back(s);
    auto p1 = parse(v[0]), p2 = parse(v[1]);
    int coeff = p1.first - p2.first, cons = p1.second - p2.second;
    if (!coeff && !cons) return "Infinite solutions";
    if (!coeff && cons) return "No solution";
    return "x=" + to_string(-cons / coeff);
  }
};
// @lc code=end
