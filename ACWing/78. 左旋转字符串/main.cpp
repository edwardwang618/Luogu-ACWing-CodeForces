#include <iostream>
using namespace std;

class Solution {
public:
    void reverse(string& s, int i, int j) {
        while (i < j) {
            swap(s[i], s[j]);
            i++, j--;
        }
    }

    string leftRotateString(string str, int n) {
        reverse(str, 0, n - 1);
        reverse(str, n, str.size() -1);
        reverse(str, 0, str.size() - 1);
        return str;
    }
};