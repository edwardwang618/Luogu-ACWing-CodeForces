#include <vector>
using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    if (nums.empty()) return -1;
    int res = INT_MAX;
    for (int x : nums) res = min(res, x);
    return res;
  }
};