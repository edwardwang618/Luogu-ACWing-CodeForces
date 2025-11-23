/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    unordered_map<Node*, Node*> mp;
    mp[nullptr] = nullptr;
    return dfs(node, mp);
  }

  Node* dfs(Node* node, unordered_map<Node*, Node*>& mp) {
    if (auto it = mp.find(node); it != mp.end()) return it->second;
    mp[node] = new Node(node->val);
    for (auto* ne : node->neighbors) mp[node]->neighbors.push_back(dfs(ne, mp));
    return mp[node];
  }
};
// @lc code=end
