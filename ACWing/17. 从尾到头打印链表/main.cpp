#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> printListReversingly(ListNode* head) {
        vector<int> v;
        while (head) v.push_back(head->val), head = head->next;
        reverse(v.begin(), v.end());
        return v;
    }
};