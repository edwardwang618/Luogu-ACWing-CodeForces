struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x) {}
};

class Solution {
public:
    ListNode* findKthToTail(ListNode* pListHead, int k) {
        ListNode *cur = pListHead;
        while (k--) {
            if (!cur) {
                return nullptr;
            }
            
            cur = cur->next;
        }

        while (cur) {
            cur = cur->next;
            pListHead = pListHead->next;
        }
        
        return pListHead;
    }
};