/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
  using node_p = ListNode*;
  node_p removeElements(node_p head, int val) {
    node_p dummy = new ListNode(0), prev = dummy;
    while (head) {
      if (head->val != val) {
        prev->next = head;
        prev = prev->next;
      }
      head = head->next;
    }
    prev->next = 0;
    return dummy->next;
  }
};
// @lc code=end
