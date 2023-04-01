#include <iostream>
#include <algorithm>
using namespace std;

int k;
string res;

#define to_int(x) ('A' <= x && x <= 'Z' ? x - 'A' + 10 : x - '0')
#define to_char(x) (x <= 9 ? x + '0' : x - 10 + 'A')

int main() {
  scanf("%d", &k);
  string a, b;
  cin >> a >> b;

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  int t = 0;
  for (int i = 0; i < a.size() || i < b.size(); i++) {
    if (i < a.size()) t += to_int(a[i]);
    if (i < b.size()) t += to_int(b[i]);
    res += to_char(t % k);
    t /= k;
  }

  if (t) res += '1';

  reverse(res.begin(), res.end());
  cout << res << endl;
}