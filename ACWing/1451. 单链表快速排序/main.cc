struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* quickSortList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode *slow = dummy, *fast = dummy;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }    

    ListNode *l1 = dummy->next, *l2 = slow->next;
    slow->next = nullptr;
    l1 = quickSortList(l1), l2 = quickSortList(l2);
    ListNode *prev = dummy;
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

    return dummy->next;
  }
};