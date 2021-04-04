#include <vector>
using namespace std;

class Solution {
public:
    bool searchArray(vector<vector<int>> array, int target) {
        int x = array.size() - 1, y = 0;
        while (x >= 0 && y < array[0].size()) {
            if (array[x][y] < target) y++;
            else if (array[x][y] > target) x--;
            else return true;
        }

        return false;
    }
};