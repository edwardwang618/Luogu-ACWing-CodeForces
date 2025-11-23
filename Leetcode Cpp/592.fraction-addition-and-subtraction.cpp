/*
 * @lc app=leetcode id=592 lang=cpp
 *
 * [592] Fraction Addition and Subtraction
 */

// @lc code=start

class Solution {
 public:
  struct Frac {
    long x, y;
    long gcd(long x, long y) { return y ? gcd(y, x % y) : x; }
    Frac(long x, long y) {
      long g = gcd(x, y);
      this->x = x / g, this->y = y / g;
    }

    Frac& operator+(const Frac& f) {
      long a = x * f.y + y * f.x, b = y * f.y;
      long g = gcd(a, b);
      x = a / g, y = b / g;
      return *this;
    }
  };

  string fractionAddition(string s) {
    Frac f(0, 1);
    for (int i = 0; i < s.size(); i++) {
      long x, y;
      int j = i;
      while (j < s.size() && s[j] != '/') j++;
      x = stol(s.substr(i, j - i));
      i = ++j;
      while (j < s.size() && isdigit(s[j])) j++;
      y = stol(s.substr(i, j - i));
      f = f + Frac(x, y);
      i = j - 1;
    }

    long x = f.x, y = f.y;
    string res;
    if (x > 0 && y < 0 || x < 0 && y > 0) res = "-";
    res += to_string(abs(x)) + "/" + to_string(abs(y));
    return res;
  }
};
// @lc code=end
