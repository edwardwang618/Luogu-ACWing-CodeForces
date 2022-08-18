#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs1(root, res);
        if (res[res.size() - 1] == ',') res.pop_back();
        return res;
    }

    void dfs1(TreeNode* root, string& s) {
        if (!root) {
            s += "#,";
            return;
        }
        s += to_string(root->val) + ",";
        dfs1(root->left, s);
        dfs1(root->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v;
        for (int i = 0; i < data.size(); i++) {
            int j = i;
            while (j < data.size() && data[j] != ',') j++;
            v.push_back(data.substr(i, j - i));
            i = j;
        }

        int idx = 0;
        return dfs2(v, idx);
    }

    TreeNode* dfs2(vector<string> v, int& idx) {
        if (v[idx] == "#") {
            idx++;
            return nullptr;
        }

        TreeNode* cur = new TreeNode(stoi(v[idx++]));
        cur->left = dfs2(v, idx);
        cur->right = dfs2(v, idx);
        return cur;
    }
};