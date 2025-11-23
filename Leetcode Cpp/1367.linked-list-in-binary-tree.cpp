/*
 * @lc app=leetcode id=1367 lang=cpp
 *
 * [1367] Linked List in Binary Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  using ULL = unsigned long long;
  ULL P = 131, hash = 0, pow = 1;
  int n = 0;
  bool isSubPath(ListNode* head, TreeNode* root) {
    while (head) {
      hash = hash * P + head->val;
      pow *= P;
      n++;
      head = head->next;
    }

    vector<int> v;
    return dfs(root, 0, v);
  }

  bool dfs(TreeNode* cur, ULL h, vector<int> &v) {
    if (!cur) return false;
    h = h * P + cur->val;
    if (v.size() >= n) h -= v[v.size() - n] * pow;
    if (h == hash) return true;

    v.push_back(cur->val);
    if (dfs(cur->left, h, v) || dfs(cur->right, h, v)) return true;
    v.pop_back();
    return false;
  }
};
// @lc code=end
