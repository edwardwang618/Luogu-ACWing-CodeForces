/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
    int n1 = 0, n2 = 0;
    for (ListNode *p = l1; p; p = p->next) n1++;
    for (ListNode *p = l2; p; p = p->next) n2++;
    if (n1 < n2) {
      swap(l1, l2);
      swap(n1, n2);
    }
    while (n1 > n2) {
      l1 = l1->next;
      n1--;
    }

    while (l1 != l2) l1 = l1->next, l2 = l2->next;
    return l1;
  }
};
// @lc code=end
