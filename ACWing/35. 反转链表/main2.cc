struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *res = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return res;
    }
};