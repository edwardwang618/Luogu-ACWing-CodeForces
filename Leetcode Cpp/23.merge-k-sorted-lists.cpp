/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
  // ListNode* mergeKLists(vector<ListNode*>& lists) {
  //   auto cmp = [&](auto& p1, auto& p2) { return p1->val > p2->val; };
  //   priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap(cmp);
  //   for (auto* p : lists) if (p) heap.push(p);
  //   auto dummy = new ListNode(0), cur = dummy;
  //   while (heap.size()) {
  //     auto p = heap.top();
  //     heap.pop();
  //     cur->next = p;
  //     cur = cur->next;
  //     if (p->next) heap.push(p->next);
  //   }
  //   return dummy->next;
  // }

  ListNode* merge(vector<ListNode*>& v, int l, int r) {
    if (l > r) return nullptr;
    if (l == r) return v[l];
    int mid = l + (r - l >> 1);
    auto left = merge(v, l, mid), right = merge(v, mid + 1, r);
    ListNode dummy;
    auto cur = &dummy;
    while (left || right) {
      if (!left) {
        cur->next = right;
        break;
      } else if (!right) {
        cur->next = left;
        break;
      } else {
        if (left->val <= right->val)
          cur->next = left, left = left->next;
        else
          cur->next = right, right = right->next;
        cur = cur->next;
      }
    }
    return dummy.next;
  }

  ListNode* mergeKLists(vector<ListNode*>& v) {
    return merge(v, 0, v.size() - 1);
  }
};
// @lc code=end
