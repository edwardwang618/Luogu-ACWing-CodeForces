/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
  // ListNode* reverseList(ListNode* head) {
  //   ListNode *tmp, *prev = nullptr;
  //   while (head) {
  //     tmp = head->next;
  //     head->next = prev;
  //     prev = head;
  //     head = tmp;
  //   }
  //   return prev;
  // }

  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    auto res = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return res;
  }
};
// @lc code=end
