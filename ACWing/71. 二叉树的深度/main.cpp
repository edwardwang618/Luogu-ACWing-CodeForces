#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int treeDepth(TreeNode* root) {
        if (!root) return 0;
        return max(treeDepth(root->left), treeDepth(root->right)) + 1;        
    }
};