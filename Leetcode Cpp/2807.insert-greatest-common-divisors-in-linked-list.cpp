/*
 * @lc app=leetcode id=2807 lang=cpp
 *
 * [2807] Insert Greatest Common Divisors in Linked List
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
  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    auto res = head;
    auto gcd = [](int x, int y) {
      while (y) {
        x %= y;
        swap(x, y);
      }
      return x;
    };
    while (head && head->next) {
      auto tmp = head->next;
      head->next = new ListNode(gcd(head->val, tmp->val), tmp);
      head = tmp;
    }
    return res;
  }
};
// @lc code=end
