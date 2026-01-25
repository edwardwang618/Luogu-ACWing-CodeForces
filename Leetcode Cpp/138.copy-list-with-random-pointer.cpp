/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  // Node *copyRandomList(Node *head) {
  //   unordered_map<Node *, Node *> mp{{nullptr, nullptr}};
  //   auto dfs = [&](this auto &&dfs, Node *p) -> Node * {
  //     if (auto it = mp.find(p); it != mp.end())
  //       return it->second;

  //     Node *node = new Node(p->val);
  //     mp[p] = node;
  //     node->next = dfs(p->next);
  //     node->random = dfs(p->random);
  //     return node;
  //   };
  //   return dfs(head);
  // }

  Node *copyRandomList(Node *head) {
    // A->A'->B->B'->...
    for (Node *p = head; p; p = p->next->next) {
      Node *np = new Node(p->val);
      np->next = p->next;
      p->next = np;
    }

    for (Node *p = head; p; p = p->next->next)
      p->next->random = p->random ? p->random->next : nullptr;

    Node dummy(0), *prev = &dummy;
    for (Node *p = head; p; p = p->next) {
      prev->next = p->next;
      p->next = p->next->next;
      prev = prev->next;
    }
    return dummy.next;
  }
};
// @lc code=end
