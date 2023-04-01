#include <iostream>
#include <algorithm>
using namespace std;

string res;
string s1, s2;

int main() {
  cin >> s1;
  cin >> s2;

  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());

  int t = 0;
  for (int i = 0; i < s1.size() || i < s2.size(); i++) {
    if (i < s1.size()) t += s1[i] - '0';
    if (i < s2.size()) t += s2[i] - '0';
    res += '0' + t % 10;
    t /= 10;
  }

  if (t) res += '1';

  reverse(res.begin(), res.end());
  cout << res << endl;
}