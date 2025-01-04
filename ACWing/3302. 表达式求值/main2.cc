#include <iostream>
using namespace std;

string s;

void update(int &a, int &b, int x, char op) {
  switch (op) {
    case '+': a += b, b = x; break;
    case '-': a += b, b = -x; break;
    case '*': b *= x; break;
    case '/': b /= x; break;
  }
}

int dfs(int &idx, int a, int b) {
  char op = '+';
  while (idx < s.size()) {
    char ch = s[idx];
    if (ch == ')') {
      idx++;
      return a + b;
    }
    if (!isdigit(ch) && ch != '(') {
      op = ch;
      idx++;
    }
    if (ch == '(') {
      idx++;
      int x = dfs(idx, 0, 0);
      update(a, b, x, op);
    }
    if (isdigit(ch)) {
      int j = idx;
      while (j < s.size() && isdigit(s[j])) j++;
      int x = stoi(s.substr(idx, j - idx));
      update(a, b, x, op);
      idx = j;
    }
  }
  return a + b;
}

int main() {
  cin >> s;
  int idx = 0;
  printf("%d\n", dfs(idx, 0, 0));
}