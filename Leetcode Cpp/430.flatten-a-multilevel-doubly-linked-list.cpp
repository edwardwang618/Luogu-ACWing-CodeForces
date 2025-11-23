/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
 public:
  Node* flatten(Node* head) {
    dfs(head);
    return head;
  }

  Node* dfs(Node* head) {
    Node *cur = head, *res = head;
    while (cur) {
      if (cur->child) {
        Node* tail = dfs(cur->child);
        tail->next = cur->next;
        if (tail->next) tail->next->prev = tail;
        cur->next = cur->child;
        cur->next->prev = cur;
        cur->child = nullptr;
        cur = tail;
      }

      res = cur;
      cur = cur->next;
    }

    return res;
  }
};
// @lc code=end
