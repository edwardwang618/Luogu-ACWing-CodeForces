/*
 * @lc app=leetcode id=2296 lang=cpp
 *
 * [2296] Design a Text Editor
 */

// @lc code=start
class TextEditor {
  string left, right;
  string getLeft10() {
    int len = min(10, (int)left.size());
    return left.substr(left.size() - len);
  }

public:
  TextEditor() {}

  void addText(const string &text) { left += text; }

  int deleteText(int k) {
    int del = min((int)left.size(), k);
    left.resize(left.size() - del);
    return del;
  }

  string cursorLeft(int k) {
    while (k-- && left.size()) {
      right += left.back();
      left.pop_back();
    }
    return getLeft10();
  }

  string cursorRight(int k) {
    while (k-- && right.size()) {
      left += right.back();
      right.pop_back();
    }
    return getLeft10();
  }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
// @lc code=end
