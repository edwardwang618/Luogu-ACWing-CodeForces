#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
        ListNode *prev = new ListNode(0), *res = prev, *cur = head;
        while (cur) {
            ListNode* tmp = cur;
            while (tmp->next && tmp->next->val == cur->val) tmp = tmp->next;
            if (tmp == cur) {
                prev->next = cur;
                prev = prev->next;
            }
            cur = tmp->next;
        }

        prev->next = nullptr;
        return res->next;
    }
};