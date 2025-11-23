/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root) return "#";
    return to_string(root->val) + "," + serialize(root->left) + "," +
           serialize(root->right);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    stringstream ss(data);
    vector<string> v;
    for (string s; getline(ss, s, ',');) v.push_back(s);
    int idx = 0;
    return dfs(idx, v);
  }

  TreeNode* dfs(int& idx, vector<string>& v) {
    if (v[idx] == "#") {
      idx++;
      return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(v[idx++]));
    root->left = dfs(idx, v);
    root->right = dfs(idx, v);
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
