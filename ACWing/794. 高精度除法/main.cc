#include <iostream>
#include <string>
using namespace std;

string div(string& a, int b, int& r) {
  string res;
  r = 0;

  for (int i = 0; i < a.size(); i++) {
    r = r * 10 + (a[i] - '0');
    res.push_back(r / b + '0');
    r %= b;
  }

  int i = 0;
  while (i + 1 < res.size() && res[i] == '0') i++;
  return res.substr(i);
}

int main() {
  string a;
  int b;
  cin >> a >> b;

  int r;
  cout << div(a, b, r) << '\n' << r << endl;
}
