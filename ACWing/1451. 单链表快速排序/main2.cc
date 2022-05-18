struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *quickSortList(ListNode *head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy;
    for (int k = 1, sorted = 0; !sorted; k <<= 1, prev = dummy) {
      sorted = true;
      while (prev->next) {
        ListNode *slow = prev, *fast = prev;
        for (int i = 0; i < k && slow; i++) {
          slow = slow->next;
          if (fast && fast->next) fast = fast->next->next;
        }
        if (!slow) break;
        ListNode *tail = nullptr;
        if (fast) {
          tail = fast->next;
          fast->next = nullptr;
        }
        ListNode *l1 = prev->next, *l2 = slow->next;
        slow->next = nullptr;
        while (l1 || l2) {
          if (!l1) {
            prev->next = l2;
            break;
          }
          if (!l2) {
            prev->next = l1;
            break;
          }
          if (l1->val <= l2->val) {
            prev->next = l1;
            l1 = l1->next;
          } else {
            prev->next = l2;
            l2 = l2->next;
          }
          prev = prev->next;
        }
        while (prev->next) prev = prev->next;
        prev->next = tail;
        sorted = false;
      }
    }

    return dummy->next;
  }
};