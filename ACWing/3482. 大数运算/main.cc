#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  vector<int> x, y;
  for (int i = a.size() - 1; i >= 0; i--)
    if (a[i] != '-') x.push_back(a[i] - '0');
  for (int i = b.size() - 1; i >= 0; i--)
    if (b[i] != '-') y.push_back(b[i] - '0');
  int sgn1 = a[0] == '-' ? -1 : 1, sgn2 = b[0] == '-' ? -1 : 1;
  auto add = [](auto& a, auto& b) {
    vector<int> res;
    for (int i = 0, t = 0; i < a.size() || i < b.size() || t; i++) {
      if (i < a.size()) t += a[i];
      if (i < b.size()) t += b[i];
      res.push_back(t % 10);
      t /= 10;
    }
    while (res.size() > 1 && !res.back()) res.pop_back();
    string s;
    for (int i = res.size() - 1; i >= 0; i--) s += '0' + res[i];
    return s;
  };
  auto cmp = [](auto& a, auto& b) {
    if (a.size() < b.size())
      return -1;
    else if (a.size() > b.size())
      return 1;

    for (int i = a.size() - 1; i >= 0; i--)
      if (a[i] < b[i])
        return -1;
      else if (a[i] > b[i])
        return 1;
    return 0;
  };
  auto sub = [&cmp](auto& a, auto& b) {
    int sgn = cmp(a, b);
    if (sgn == -1) swap(a, b);
    vector<int> res;
    for (int i = 0, t = 0; i < a.size(); i++) {
      int x = a[i] - (i < b.size() ? b[i] : 0) - t;
      if (x >= 0) {
        res.push_back(x);
        t = 0;
      } else {
        res.push_back(x + 10);
        t = 1;
      }
    }
    while (res.size() > 1 && !res.back()) res.pop_back();
    string s;
    for (int i = res.size() - 1; i >= 0; i--) s += '0' + res[i];
    if (sgn == -1) s = "-" + s;
    return s;
  };
  auto mult = [](auto& a, auto& b) {
    vector<int> res(a.size() + b.size());
    for (int i = 0; i < a.size(); i++)
      for (int j = 0; j < b.size(); j++) res[i + j] += a[i] * b[j];
    for (int i = 0, t = 0; i < res.size() || t; i++) {
      if (i == res.size()) res.push_back(0);
      t += res[i];
      res[i] = t % 10;
      t /= 10;
    }
    while (res.size() > 1 && !res.back()) res.pop_back();
    string s;
    for (int i = res.size() - 1; i >= 0; i--) s += '0' + res[i];
    return s;
  };

  // +
  if (sgn1 * sgn2 == 1) {
    if (sgn1 == -1) putchar('-');
    cout << add(x, y) << endl;
  } else {
    if (sgn1 == -1)
      cout << sub(y, x) << endl;
    else
      cout << sub(x, y) << endl;
  }
  // -
  if (sgn1 * sgn2 == -1) {
    if (sgn1 == -1) putchar('-');
    cout << add(x, y) << endl;
  } else {
    if (sgn1 == 1)
      cout << sub(x, y) << endl;
    else
      cout << sub(y, x) << endl;
  }

  // *
  auto s = mult(x, y);
  if (sgn1 * sgn2 == -1 && s != "0") putchar('-');
  cout << s << endl;
}