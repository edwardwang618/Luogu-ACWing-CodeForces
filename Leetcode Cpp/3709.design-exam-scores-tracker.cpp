/*
 * @lc app=leetcode id=3709 lang=cpp
 *
 * [3709] Design Exam Scores Tracker
 */

// @lc code=start
class ExamTracker {
  vector<int> ts;
  using ll = long long;
  vector<ll> sum;

public:
  ExamTracker() : sum({0}) {}

  void record(int time, int score) {
    ts.push_back(time);
    sum.push_back(sum.back() + score);
  }

  ll totalScore(int startTime, int endTime) {
    int l = lower_bound(ts.begin(), ts.end(), startTime) - ts.begin(),
        r = upper_bound(ts.begin(), ts.end(), endTime) - ts.begin();
    return sum[r] - sum[l];
  }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
// @lc code=end
