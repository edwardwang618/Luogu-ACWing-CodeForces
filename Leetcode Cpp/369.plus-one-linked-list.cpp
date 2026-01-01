/*
 * @lc app=leetcode id=369 lang=cpp
 *
 * [369] Plus One Linked List
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
  ListNode *plusOne(ListNode *head) {
    auto reverse = [](auto *head) {
      ListNode *prev = nullptr;
      while (head) {
        auto tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
      }
      return prev;
    };

    head = reverse(head);
    auto *res = head;
    int t = 1;
    for (; head; head = head->next) {
      t += head->val;
      head->val = t % 10;
      t /= 10;
    }
    res = reverse(res);
    if (t) return new ListNode(1, res);
    return res;
  }
};
// @lc code=end
