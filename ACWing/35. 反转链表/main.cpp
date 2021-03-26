struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *tmp = nullptr;
        while (head) {
            tmp = head -> next;
            head -> next = prev;
            prev = head;
            head = tmp;
        }

        return prev;
    }
};