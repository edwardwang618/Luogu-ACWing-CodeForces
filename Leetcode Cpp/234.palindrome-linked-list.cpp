/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
  bool isPalindrome(ListNode *head) {
    ListNode dummy(0, head);
    auto fast = &dummy, slow = &dummy;
    while (fast && fast->next)
      slow = slow->next, fast = fast->next->next;
    auto rev = [&](auto head) {
      ListNode *prev = nullptr;
      while (head) {
        auto tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
      }
      return prev;
    };
    return [](auto l1, auto l2) {
      while (l1 && l2) {
        if (l1->val != l2->val)
          return false;
        l1 = l1->next;
        l2 = l2->next;
      }
      return true;
    }(dummy.next, rev(slow->next));
  }
};
// @lc code=end
