/*
 * @lc app=leetcode id=428 lang=cpp
 *
 * [428] Serialize and Deserialize N-ary Tree
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// class Codec {
//  public:
//   // Encodes a tree to a single string.
//   string serialize(Node* root) {
//     string s;
//     dfs(root, s);
//     return s;
//   }

//   void dfs(Node* cur, string& s) {
//     if (!cur) return;
//     s += to_string(cur->val) + ",";
//     if (cur->children.empty()) return;

//     if (s.back() == ',') s.pop_back();
//     s += '(';
//     for (auto* ne : cur->children) dfs(ne, s);
//     if (s.back() == ',') s.pop_back();
//     s += ')';
//   }

//   // Decodes your encoded data to tree.
//   Node* deserialize(string s) {
//     if (s.empty()) return nullptr;
//     if (s.back() == ',') return new Node(stoi(s.substr(0, s.size() - 1)));
//     Node* root = nullptr;
//     stack<Node*> stk;
//     for (int i = 0; i < s.size(); i++) {
//       if (s[i] == '(') {
//         auto children = stk.top()->children;
//         if (children.size()) stk.push(children.back());
//       } else if (isdigit(s[i])) {
//         int j = i;
//         while (j < s.size() && isdigit(s[j])) j++;
//         Node* node = new Node(stoi(s.substr(i, j - i)));
//         if (stk.size()) stk.top()->children.push_back(node);
//         else stk.push(node);
//         i = j - 1;
//       } else if (s[i] == ')') {
//         root = stk.top();
//         stk.pop();
//       }
//     }

//     return root;
//   }
// };

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(Node* root) {
    string s;
    if (!root) return s;
    queue<Node*> q;
    q.push(root);
    while (q.size()) {
      auto* t = q.front();
      q.pop();
      s += to_string(t->val) + "," + to_string(t->children.size()) + ",";
      for (auto* ne : t->children) q.push(ne);
    }
    return s;
  }

  // Decodes your encoded data to tree.
  Node* deserialize(string s) {
    if (s.empty()) return nullptr;
    int idx = 0;
    auto [val, cnt] = get_num(s, idx);
    Node* root = new Node(val);
    queue<pair<Node*, int>> q;
    q.push({root, cnt});
    while (idx < s.size()) {
      auto t = q.front();
      q.pop();
      Node* node = t.first;
      int cnt = t.second;
      for (int i = 0; i < cnt; i++) {
        auto [val, child_cnt] = get_num(s, idx);
        auto* child = new Node(val);
        node->children.push_back(child);
        q.push({child, child_cnt});
      }
    }

    return root;
  }

  pair<int, int> get_num(string& s, int& i) {
    int j = i;
    while (j < s.size() && isdigit(s[j])) j++;
    int val = stoi(s.substr(i, j - i));
    i = j + 1;
    j = i;
    while (j < s.size() && isdigit(s[j])) j++;
    int cnt = stoi(s.substr(i, j - i));
    i = j + 1;
    return {val, cnt};
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
