/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 */

// @lc code=start
class SmallestInfiniteSet {
public:
  vector<bool> v;
  int smallest;
  SmallestInfiniteSet() : smallest(1) { v.resize(1001, true); }

  int popSmallest() {
    int x = smallest;
    v[smallest] = false;
    while (smallest <= 1000 && !v[smallest])
      smallest++;
    return x;
  }

  void addBack(int x) {
    v[x] = true;
    if (x < smallest)
      smallest = x;
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end
