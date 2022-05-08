struct ListNode {
  int val;
  ListNode *next, *random;
  ListNode(int x) : val(x), next(NULL), random(NULL) {}
};

class Solution {
public:
  ListNode *copyRandomList(ListNode *head) {
    ListNode *dummy = new ListNode(0), *prev = dummy;
    ListNode *tmp = head;
    while (tmp) {
      ListNode *node = new ListNode(tmp->val);
      node->next = tmp->next;
      tmp->next = node;
      tmp = node->next;
    }

    tmp = head;
    while (tmp) {
      if (tmp->random) tmp->next->random = tmp->random->next;
      tmp = tmp->next->next;
    }

    tmp = head;
    while (tmp) {
      prev->next = tmp->next;
      prev = prev->next;
      tmp->next = tmp->next->next;
      tmp = tmp->next;
    }

    return dummy->next;
  }
};