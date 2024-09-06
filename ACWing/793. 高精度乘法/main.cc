#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string mult(string& a, int b) {
  if (b == 0) return "0";

  string res;

  int t = 0;
  for (int i = a.size() - 1; i >= 0; i--) {
    int prod = (a[i] - '0') * b + t;
    res.push_back(prod % 10 + '0');
    t = prod / 10;
  }

  while (t) {
    res.push_back(t % 10 + '0');
    t /= 10;
  }

  reverse(res.begin(), res.end());
  return res;
}

int main() {
  string a;
  int b;

  cin >> a >> b;
  cout << mult(a, b) << endl;
}
