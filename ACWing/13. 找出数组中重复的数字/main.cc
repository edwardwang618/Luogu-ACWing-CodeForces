#include <vector>
using namespace std;

class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        for (auto &x : nums) {
            if (x < 0 || x >= nums.size()) return -1;
            x++;
        }

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i], y = abs(x) - 1;
            if (nums[y] < 0) return abs(x) - 1;
            nums[y] = -nums[y];
        }

        return -1;
    }
};