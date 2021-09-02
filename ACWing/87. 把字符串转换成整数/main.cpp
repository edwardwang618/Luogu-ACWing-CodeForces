#include <iostream>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        int k = 0;
        while (k < str.size() && str[k] == ' ') k++;
        bool is_neg = false;
        if (str[k] == '-') is_neg = true, k++;
        else if (str[k] == '+') k++;

        long res = 0;
        while (k < str.size() && '0' <= str[k] && str[k] <= '9')
            res = res * 10 + str[k++] - '0';

        if (is_neg) res = -res;
        if (res > INT_MAX) res = INT_MAX;
        if (res < INT_MIN) res = INT_MIN;
        return (int) res;
    }
};