#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int> > res;
    vector<int> path;

    vector<vector<int> > findPath(TreeNode* root, int sum) {
        dfs(root, 0, sum);
        return res;
    }

    void dfs(TreeNode *cur, int s, int sum) {
        if (!cur) return;

        s += cur->val;
        path.push_back(cur->val);
        if (!cur->left && !cur->right) {
            if (s == sum) res.push_back(path);
            path.pop_back();
            return;
        }

        if (cur->left) dfs(cur->left, s, sum);
        if (cur->right) dfs(cur->right, s, sum);
        path.pop_back();
    }
};