/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
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
    if (!root) return "";
    return to_string(root->val) + "," + serialize(root->left) +
           serialize(root->right);
  }

  // Decodes your encoded data to tree.
  // TreeNode* deserialize(string s) {
  //   int idx = 0;
  //   return dfs(idx, s, INT_MIN, INT_MAX);
  // }

  // TreeNode* dfs(int& idx, string& s, int min, int max) {
  //   if (idx == s.size()) return nullptr;
  //   int i = idx;
  //   while (s[i] != ',') i++;
  //   int val = stoi(s.substr(idx, i - idx));
  //   if (min < val && val < max) {
  //     idx = i + 1;
  //     TreeNode* root = new TreeNode(val);
  //     root->left = dfs(idx, s, min, val);
  //     root->right = dfs(idx, s, val, max);
  //     return root;
  //   } else
  //     return nullptr;
  // }
  TreeNode* deserialize(string data) {
    istringstream ss(data);
    vector<string> v;
    for (string s; getline(ss, s, ',');) v.push_back(s);
    if (v.empty()) return nullptr;
    stack<TreeNode*> stk;
    TreeNode* root = new TreeNode(stoi(v[0]));
    stk.push(root);
    for (int i = 1; i < v.size(); i++) {
      int x = stoi(v[i]);
      if (stk.empty() || x < stk.top()->val) {
        TreeNode* node = new TreeNode(x);
        if (stk.size()) stk.top()->left = node;
        stk.push(node);
      } else {
        TreeNode* node = nullptr;
        while (stk.size() && x > stk.top()->val) {
          node = stk.top();
          stk.pop();
        }
        node->right = new TreeNode(x);
        stk.push(node->right);
      }
    }

    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
