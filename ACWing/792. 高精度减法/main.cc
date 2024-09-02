#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool cmp(auto& a, auto& b) {
  if (a.size() != b.size()) return a.size() >= b.size();
  return a >= b;
}

string sub(auto& a, auto& b) {
  string c;
  c.reserve(a.size());

  for (int i = 0, t = 0; i < a.size(); ++i) {
    int x = a[a.size() - 1 - i] - '0';
    int y = (i < b.size() ? b[b.size() - 1 - i] - '0' : 0);
    int diff = x - y - t;

    if (diff < 0) {
      diff += 10;
      t = 1;
    } else
      t = 0;

    c += diff + '0';
  }

  while (c.size() > 1 && c.back() == '0') c.pop_back();

  reverse(c.begin(), c.end());
  return c;
}

int main() {
  string a, b;
  getline(cin, a);
  getline(cin, b);

  cout << (cmp(a, b) ? sub(a, b) : "-" + sub(b, a)) << endl;
}
