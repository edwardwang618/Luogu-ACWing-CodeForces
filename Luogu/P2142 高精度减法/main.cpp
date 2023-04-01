#include <iostream>
#include <algorithm>
using namespace std;

string res;

bool cmp(string &a, string &b) {
  if (a.size() != b.size()) return a.size() > b.size();
  for (int i = 0; i < a.size(); i++)
    if (a[i] < b[i]) return false;
  return true;
}

int main() {
  string a, b;
  cin >> a;
  cin >> b;

  int sign = 0;
  if (!cmp(a, b)) {
    swap(a, b);
    sign = -1;
  }

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (int i = 0, t = 0; i < a.size(); i++) {
    t = a[i] - '0' - t;
    if (i < b.size()) t -= b[i] - '0';
    res += '0' + (t + 10) % 10;
    t = t < 0 ? 1 : 0;
  }

  while (res.size() > 1 && res.back() == '0') res.pop_back();

  if (sign == -1) printf("-");
  reverse(res.begin(), res.end());
  cout << res << endl;
}