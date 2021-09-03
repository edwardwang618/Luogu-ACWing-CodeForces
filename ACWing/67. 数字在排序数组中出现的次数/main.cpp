#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getNumberOfK(vector<int>& nums , int k) {
        int res = 0;
        for (int x : nums) if (x == k) res++;
        return res;
    }
};