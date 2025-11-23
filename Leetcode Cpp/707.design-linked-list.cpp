/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
class MyLinkedList {
 public:
  struct Node {
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
  }* head;

  MyLinkedList() { head = nullptr; }

  int get(int idx) {
    if (idx < 0) return -1;
    auto p = head;
    for (int i = 0; i < idx && p; i++) p = p->next;
    if (!p) return -1;
    return p->val;
  }

  void addAtHead(int val) {
    auto p = new Node(val);
    p->next = head;
    head = p;
  }

  void addAtTail(int val) {
    if (!head) {
      head = new Node(val);
      return;
    }

    auto p = head;
    while (p->next) p = p->next;
    p->next = new Node(val);
  }

  void addAtIndex(int idx, int val) {
    if (idx <= 0) {
      addAtHead(val);
      return;
    }

    auto p = head;
    for (int i = 0; i < idx - 1 && p; i++) p = p->next;
    if (!p) return;
    auto node = new Node(val);
    node->next = p->next;
    p->next = node;
  }

  void deleteAtIndex(int idx) {
    if (!idx) {
      head = head->next;
      return;
    }

    auto p = head;
    for (int i = 0; i < idx - 1 && p; i++) p = p->next;
    if (!p || !p->next) return;
    p->next = p->next->next;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
