/*
 * @lc app=leetcode id=1286 lang=cpp
 *
 * [1286] Iterator for Combination
 */

// @lc code=start
class CombinationIterator {
 public:
  string s;
  int n, m, state;
  CombinationIterator(string characters, int combinationLength) {
    s = characters;
    n = s.size(), m = combinationLength, state = 0;
    for (int i = 0; i < m; i++) state |= 1 << i;
  }

  string next() {
    string res;
    for (int i = 0; i < n; i++)
      if (state >> i & 1) res += s[i];

    int k = n - 1;
    while (k >= 0 && (state >> k & 1)) k--;
    if (n - k - 1 == m)
      state = -1;
    else {
      int cnt = n - k;
      while (k >= 0 && !(state >> k & 1)) k--;
      for (int i = k; i < n; i++)
        if (state >> i & 1) state -= 1 << i;
      for (int i = k + 1, j = 0; j < cnt; i++, j++) state |= 1 << i;
    }

    return res;
  }

  bool hasNext() { return ~state; }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters,
 * combinationLength); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */
// @lc code=end
