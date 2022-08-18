#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getNumberSameAsIndex(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l >> 1);
            if (nums[m] >= m) r = m;
            else l = m + 1;
        }

        return nums[l] == l ? l : -1;
    }
};