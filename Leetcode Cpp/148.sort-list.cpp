/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next)
      return head;

    int n = 0;
    for (auto p = head; p; p = p->next, n++)
      ;

    ListNode dummy(0, head);
    auto split = [](auto head, int step) -> decltype(head) {
      for (int i = 1; i < step && head; i++, head = head->next)
        ;
      if (!head)
        return nullptr;
      auto res = head->next;
      head->next = nullptr;
      return res;
    };
    auto merge = [](auto l1, auto l2, auto tail) {
      while (l1 && l2) {
        if (l1->val <= l2->val)
          tail->next = l1, l1 = l1->next;
        else
          tail->next = l2, l2 = l2->next;
        tail = tail->next;
      }
      tail->next = l1 ? l1 : l2;
      while (tail->next)
        tail = tail->next;
      return tail;
    };
    for (int step = 1; step < n; step <<= 1) {
      auto prev = &dummy, cur = dummy.next;
      while (cur) {
        auto left = cur;
        auto right = split(left, step);
        cur = split(right, step);
        prev = merge(left, right, prev);
      }
    }
    return dummy.next;
  }
};
// @lc code=end
