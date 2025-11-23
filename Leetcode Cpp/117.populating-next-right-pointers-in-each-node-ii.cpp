/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return nullptr;
    queue<Node*> q;
    q.push(root);

    Node* prev = nullptr;
    while (q.size()) {
      for (int i = q.size(); i; i--) {
        auto cur = q.front();
        q.pop();
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
        // 如果是第一个节点，保存起来；
        // 否则将next指向当前节点并更新prev
        if (!prev)
          prev = cur;
        else {
          prev->next = cur;
          prev = cur;
        }
      }

      prev = nullptr;
    }
    return root;
  }
};
// @lc code=end
