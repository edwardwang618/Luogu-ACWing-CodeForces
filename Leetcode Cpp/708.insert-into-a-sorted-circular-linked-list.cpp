/*
 * @lc app=leetcode id=708 lang=cpp
 *
 * [708] Insert into a Sorted Circular Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
 public:
  Node* insert(Node* head, int x) {
    if (!head) {
      auto res = new Node(x);
      res->next = res;
      return res;
    }
    auto add = [&](Node* cur, int x) {
      auto n = new Node(x);
      n->next = cur->next;
      cur->next = n;
    };
    auto cur = head;
    do {
      if (cur->val <= x && x <= cur->next->val) {
        add(cur, x);
        return head;
      }
      cur = cur->next;
    } while (cur != head);
    cur = head;
    do {
      if (cur->val > cur->next->val) {
        add(cur, x);
        return head;
      }
      cur = cur->next;
    } while (cur != head);
    add(cur, x);
    return head;
  }
};
// @lc code=end
