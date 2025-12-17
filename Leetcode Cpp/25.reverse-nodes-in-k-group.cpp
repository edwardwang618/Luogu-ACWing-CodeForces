/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!k || k == 1) return head;
    ListNode dummy;
    auto *prev = &dummy;
    dummy.next = head;

    while (prev) prev = swap(prev, k);
    return dummy.next;
  }

  // prev->a1->...->ak
  ListNode *swap(ListNode *prev, int k) {
    ListNode *ak = prev;
    for (int i = 0; i < k; i++) {
      ak = ak->next;
      if (!ak) return nullptr;
    }

    ListNode *akp1 = ak->next, *a1 = prev->next;
    ak->next = nullptr;
    prev->next = reverse(a1);
    a1->next = akp1;
    return a1;
  }

  ListNode *reverse(ListNode *head) {
    ListNode *tmp, *prev;
    while (head) {
      tmp = head->next;
      head->next = prev;
      prev = head;
      head = tmp;
    }

    return prev;
  }
};
// @lc code=end
