struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x) {}
};

class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0), *prev = dummy;
        while (l1 || l2) {
            if (!l2) {
                prev->next = l1;
                l1 = l1->next;
                prev = prev->next;
            } else if (!l1) {
                prev->next = l2;
                l2 = l2->next;
                prev = prev->next;
            } else {
                if (l1->val < l2->val) {
                    prev->next = l1;
                    l1 = l1->next;
                } else {
                    prev->next = l2;
                    l2 = l2->next;
                }

                prev = prev->next;
            }
        }

        return dummy->next;
    }  
};