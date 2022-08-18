#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l >> 1);
            if (nums[m] == m) l = m + 1;
            else r = m;
        }

        return nums[l] == l ? l + 1 : l;
    }
};