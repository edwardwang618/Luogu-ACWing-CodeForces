#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void quick_select(vector<int>& v, int l, int r, int idx) {
        if (l >= r) return;
        int x = v[l + (r - l >> 1)], i = l, j = r;
        while (i <= j) {
            while (v[i] < x) i++;
            while (v[j] > x) j--;
            if (i <= j) {
                swap(v[i], v[j]);
                i++;
                j--;
            }
        }
        
        if (idx <= j) quick_select(v, l, j, idx);
        else if (idx >= i) quick_select(v, i, r, idx);
        else return;
    }

    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        quick_select(input, 0, input.size() - 1, k - 1);
        sort(input.begin(), input.begin() + k);
        vector<int> res;
        for (int i = 0; i < k; i++) res.push_back(input[i]);
        return res;
    }
};