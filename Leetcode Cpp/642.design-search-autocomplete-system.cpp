/*
 * @lc app=leetcode id=642 lang=cpp
 *
 * [642] Design Search Autocomplete System
 */

// @lc code=start
class AutocompleteSystem {
  using FSS = function<bool(string&, string&)>;
  struct Node {
    unordered_map<char, Node*> ne;
    priority_queue<string, vector<string>, FSS> heap;
    unordered_set<string> inHeap;
    Node(FSS cmp) : heap(cmp) {}
  };

  struct Trie {
    Node* root;
    FSS cmp;

    Trie(FSS cmp) : cmp(cmp) { root = new Node(cmp); }

    void insert(string& s, int times, auto& mp) {
      mp[s] += times;
      Node* cur = root;
      addToHeap(s, cur);
      for (char ch : s) {
        if (!cur->ne[ch]) cur->ne[ch] = new Node(cmp);
        cur = cur->ne[ch];
        addToHeap(s, cur);
      }
    }

    void addToHeap(string& s, Node* node) {
      if (node->inHeap.find(s) == node->inHeap.end()) {
        node->heap.push(s);
        node->inHeap.insert(s);
        if (node->heap.size() > 3) {
          node->inHeap.erase(node->heap.top());
          node->heap.pop();
        }
      }
    }
  };

  Trie* trie;
  unordered_map<string, int> mp;
  FSS cmp;
  string input_str;

 public:
  AutocompleteSystem(vector<string>& ss, vector<int>& ts) {
    cmp = [&](string& s1, string& s2) {
      int t1 = mp[s1], t2 = mp[s2];
      return t1 != t2 ? t1 > t2 : s1 < s2;
    };

    trie = new Trie(cmp);
    for (int i = 0; i < ss.size(); ++i) trie->insert(ss[i], ts[i], mp);
  }

  vector<string> input(char c) {
    if (c == '#') {
      trie->insert(input_str, 1, mp);
      input_str.clear();
      return {};
    }

    input_str += c;
    Node* cur = trie->root;
    for (char ch : input_str) {
      if (!cur->ne[ch]) return {};
      cur = cur->ne[ch];
    }

    auto cp = cur->heap;
    vector<string> res;
    while (!cp.empty()) {
      res.push_back(cp.top());
      cp.pop();
    }
    sort(res.begin(), res.end(), cmp);
    return res;
  }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
// @lc code=end
