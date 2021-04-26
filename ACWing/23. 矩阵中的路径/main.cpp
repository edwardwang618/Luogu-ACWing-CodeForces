#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int d[5] = {1, 0, -1, 0, 1};
    bool hasPath(vector<vector<char>>& matrix, string& str) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(i, j, matrix, 0, str)) return true;
        
        return false;
    }

    bool dfs(int x, int y, vector<vector<char>>& matrix, int pos, string& str) {
        if (matrix[x][y] != str[pos]) return false;
        if (pos == str.size() - 1) return true;

        char ch = matrix[x][y];
        matrix[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[i + 1];
            if (0 <= nx && nx < matrix.size() && 0 <= ny && ny < matrix[0].size()) {
                if (dfs(nx, ny, matrix, pos + 1, str)) return true;
            }
        }
        matrix[x][y] = ch;

        return false;
    }
};