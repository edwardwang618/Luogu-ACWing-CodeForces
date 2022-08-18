#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_set<int> s;
        for (int x : nums) {
            if (s.count(target - x)) {
                res.push_back(target - x);
                res.push_back(x);
                break;
            }
            s.insert(x);
        }

        return res;
    }
};