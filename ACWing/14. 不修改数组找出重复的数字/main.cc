#include <vector>
using namespace std;

class Solution {
public:
  int duplicateInArray(vector<int>& nums) {
    int f = 0, s = 0;
    do {
      f = nums[nums[f]];
      s = nums[s];
    } while (f != s);
    
    f = 0;
    do {
      f = nums[f];
      s = nums[s];
    } while (f != s);
    
    return s;
  }
};