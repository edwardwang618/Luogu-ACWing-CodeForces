#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permutation(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> v;
        vector<bool> vis = vector<bool>(nums.size(), false);
        dfs(0, v, nums, res, vis);
        return res;
    }

    void dfs(int u, vector<int>& v, vector<int>& a, vector<vector<int>>& res, vector<bool>& vis) {
        if (u == a.size()) {
            res.push_back(v);
            return;
        }

        for (int i = 0; i < a.size(); i++) {
            if (vis[i]) continue;
            if (i && a[i] == a[i - 1] && !vis[i - 1]) continue;
            vis[i] = true;
            v.push_back(a[i]);
            dfs(u + 1, v, a, res, vis);
            vis[i] = false;
            v.pop_back();
        }
    }
};