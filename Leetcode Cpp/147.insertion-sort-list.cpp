/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
  ListNode *insertionSortList(ListNode *head) {
    ListNode dummy, *prev;
    while (head) {
      prev = &dummy;
      while (prev->next && prev->next->val <= head->val)
        prev = prev->next;
      auto tmp = prev->next;
      prev->next = head;
      head = head->next;
      prev->next->next = tmp;
    }
    return dummy.next;
  }
};
// @lc code=end
