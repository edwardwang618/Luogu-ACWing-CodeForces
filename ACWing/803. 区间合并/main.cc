#include <iostream>
#include <algorithm>
#include <vector>

#define x first
#define y second

using namespace std;
using PII = pair<int, int>;

const int N = 100010;
vector<PII> intervals;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    intervals.push_back({l, r});
  }

  sort(intervals.begin(), intervals.end());

  int res = 0, curEnd = (int)-1e10;
  for (int i = 0; i < n; i++) {
    if (intervals[i].x > curEnd) res++;
    curEnd = max(curEnd, intervals[i].y);
  }

  cout << res << endl;
}