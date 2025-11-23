/*
 * @lc app=leetcode id=972 lang=cpp
 *
 * [972] Equal Rational Numbers
 */

// @lc code=start
struct Frac {
  long x, y;
  long gcd(long x, long y) { return y ? gcd(y, x % y) : x; }
  Frac(long x, long y) {
    auto z = gcd(x, y);
    x /= z, y /= z;
    this->x = x, this->y = y;
  }
  bool operator==(const Frac &f) const { return x == f.x && y == f.y; }
};

Frac operator+(const Frac &f1, const Frac &f2) {
  long x = f1.x * f2.y + f1.y * f2.x, y = f1.y * f2.y;
  return Frac(x, y);
}

Frac operator-(const Frac &f1, const Frac &f2) {
  long x = f1.x * f2.y - f1.y * f2.x, y = f1.y * f2.y;
  return Frac(x, y);
}

class Solution {
 public:
  bool isRationalEqual(string s, string t) { return convert(s) == convert(t); }

  Frac convert(string s) {
    int idx = -1;
    for (int i = 0; i < s.size(); i++)
      if (s[i] == '.') {
        idx = i;
        break;
      }
    if (!~idx) return Frac(stol(s), 1);

    auto s1 = s.substr(0, idx), s2 = s.substr(idx + 1);
    Frac f(stol(s1), 1);
    if (s2.empty()) return f;
    idx = -1;
    long m = 1;
    for (int i = 0; i < s2.size(); i++) {
      if (s2[i] == '(') {
        idx = i;
        break;
      }
      m *= 10;
    }
    if (!~idx) return f + Frac(stol(s2), m);
    s2.pop_back();
    s1 = s2.substr(0, idx), s2 = s2.substr(idx + 1);
    Frac f1(s1.size() ? stol(s1) : 0, m);
    auto s3 = s1 + s2;
    Frac f2(stol(s3), m);
    m = 1;
    for (int i = 0; i < s2.size(); i++) m *= 10;
    auto f3 = f2 - f1;
    f3.y *= (m - 1);
    return f + f3;
  }
};
// @lc code=end
