#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        for (auto t = headA; t; t = t->next) lenA++;
        for (auto t = headB; t; t = t->next) lenB++;

        while (lenA > lenB) {
            headA = headA->next;
            lenA--;
        }
        while (lenB > lenA) {
            headB = headB->next;
            lenB--;
        }

        while (headA != headB && headA) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};