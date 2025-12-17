/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
  void reorderList(ListNode *head) {
    ListNode dummy(0, head);
    auto prev = &dummy;
    auto slow = &dummy, fast = &dummy;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    auto rev = [](auto head) {
      ListNode *prev = nullptr;
      while (head) {
        auto tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
      }
      return prev;
    };

    auto l1 = dummy.next;
    auto l2 = rev(slow->next);
    slow->next = nullptr;

    while (l1 || l2) {
      if (l1) {
        prev->next = l1;
        prev = prev->next;
        l1 = l1->next;
      }
      if (l2) {
        prev->next = l2;
        prev = prev->next;
        l2 = l2->next;
      }
    }
  }
};
// @lc code=end
