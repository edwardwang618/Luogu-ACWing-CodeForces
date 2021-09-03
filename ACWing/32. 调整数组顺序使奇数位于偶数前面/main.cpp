#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &a) {
        for (int i = 0, j = a.size() - 1; i < j; ) {
            while (i < j && a[i] % 2) i++;
            while (i < j && a[j] % 2 == 0) j--;
            swap(a[i++], a[j--]);     
        }
    }
};