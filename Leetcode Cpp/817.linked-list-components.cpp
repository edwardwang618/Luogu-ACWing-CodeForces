/*
 * @lc app=leetcode id=817 lang=cpp
 *
 * [817] Linked List Components
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  int numComponents(ListNode* head, vector<int>& a) {
    unordered_set<int> st(a.begin(), a.end());
    int res = 0;
    while (head) {
      if (st.count(head->val)) {
        res++;
        while (head && st.count(head->val)) head = head->next;
      }
      if (!head) break;
      head = head->next;
    }

    return res;
  }
};
// @lc code=end
