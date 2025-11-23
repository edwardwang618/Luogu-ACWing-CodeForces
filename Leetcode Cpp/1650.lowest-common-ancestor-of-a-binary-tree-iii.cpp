/*
 * @lc app=leetcode id=1650 lang=cpp
 *
 * [1650] Lowest Common Ancestor of a Binary Tree III
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
 public:
  Node* lowestCommonAncestor(Node* p, Node* q) {
    auto pp = p, qq = q;
    int dp = 0, dq = 0;
    while (pp) dp++, pp = pp->parent;
    while (qq) dq++, qq = qq->parent;
    if (dp < dq) swap(p, q);
    for (int i = 0; i < abs(dp - dq); i++) p = p->parent;
    while (p != q) p = p->parent, q = q->parent;
    return p;
  }
};
// @lc code=end
