#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string add(auto& a, auto& b) {
  string s;
  s.reserve(max(a.size(), b.size()) + 1);

  for (int i = a.size() - 1, j = b.size() - 1, t = 0; i >= 0 || j >= 0 || t;) {
    int sum = t;
    if (i >= 0) sum += a[i--] - '0';
    if (j >= 0) sum += b[j--] - '0';
    s.push_back(sum % 10 + '0');
    t = sum / 10;
  }

  reverse(s.begin(), s.end());
  return s;
}

int main() {
  string a, b;
  getline(cin, a);
  getline(cin, b);

  cout << add(a, b) << endl;
}
