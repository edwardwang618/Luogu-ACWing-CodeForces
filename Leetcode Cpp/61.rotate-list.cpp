/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
#define ne(cur) cur->next
  ListNode* rotateRight(ListNode* head, int k) {
    int n = 0;
    auto dummy = new ListNode(0);
    ne(dummy) = head;
    auto cur = dummy;
    while (ne(cur)) {
      n++;
      cur = ne(cur);
    }
    if (!n) return nullptr;

    k %= n;
    if (!k) return head;
    cur = dummy;
    for (int i = 0; i < n - k; i++) cur = ne(cur);
    auto nh = ne(cur);
    ne(cur) = nullptr;
    auto tail = nh;
    while (ne(tail)) tail = ne(tail);
    ne(tail) = ne(dummy);
    return nh;
  }
};
// @lc code=end
