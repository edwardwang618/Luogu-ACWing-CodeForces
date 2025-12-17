/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy, *prev = &dummy;
    while (l1 || l2) {
      if (!l1) {
        prev->next = l2;
        break;
      }
      if (!l2) {
        prev->next = l1;
        break;
      }
      if (l1->val <= l2->val) {
        prev->next = l1;
        l1 = l1->next;
      } else {
        prev->next = l2;
        l2 = l2->next;
      }
      prev = prev->next;
    }

    return dummy.next;
  }
};
// @lc code=end
