/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode dummy(0, head);
    auto *prev = &dummy;
    for (int i = 1; i < left; i++) prev = prev->next;
    auto* cur = prev->next;
    for (int i = 1; i <= right - left; i++) {
      auto* tmp = cur->next;
      cur->next = tmp->next;
      tmp->next = prev->next;
      prev->next = tmp;
    }
    return dummy.next;
  }
};
// @lc code=end
