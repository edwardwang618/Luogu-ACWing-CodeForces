/*
 * @lc app=leetcode id=2671 lang=cpp
 *
 * [2671] Frequency Tracker
 */

// @lc code=start
class FrequencyTracker {
  unordered_map<int, int> mp, freq;

public:
  FrequencyTracker() {}

  void add(int x) {
    int f = ++mp[x];
    if (f != 1)
      freq[f - 1]--;
    freq[f]++;
  }

  void deleteOne(int x) {
    int &f = mp[x];
    if (!f)
      return;
    f--;
    freq[f + 1]--;
    freq[f]++;
  }

  bool hasFrequency(int frequency) { return freq[frequency]; }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
// @lc code=end
