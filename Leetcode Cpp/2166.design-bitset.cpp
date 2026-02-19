/*
 * @lc app=leetcode id=2166 lang=cpp
 *
 * [2166] Design Bitset
 */

// @lc code=start
class Bitset {
  string bits;
  int ones;
  bool flipped;

public:
  Bitset(int size) : bits(size, '0'), ones(0), flipped(false) {}

  void fix(int idx) {
    char x = bits[idx] ^ flipped;
    if (x == '0') {
      bits[idx] = bits[idx] ^ 1;
      ones++;
    }
  }

  void unfix(int idx) {
    char x = bits[idx] ^ flipped;
    if (x != '0') {
      bits[idx] = bits[idx] ^ 1;
      ones--;
    }
  }

  void flip() {
    flipped = !flipped;
    ones = bits.size() - ones;
  }

  bool all() { return ones == bits.size(); }

  bool one() { return ones; }

  int count() { return ones; }

  string toString() {
    if (!flipped)
      return bits;
    string s(bits.size(), ' ');
    for (int i = 0; i < bits.size(); i++)
      s[i] = bits[i] ^ 1;
    return s;
  }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
// @lc code=end
