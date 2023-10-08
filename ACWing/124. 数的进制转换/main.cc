#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int ain, aout;

char get(int x) {
  if (0 <= x && x < 10)
    return '0' + x;
  else if (10 <= x && x < 36)
    return x - 10 + 'A';
  else
    return x - 36 + 'a';
}

void div(vector<int>& a, int b, int& r) {
  vector<int> c;
  r = 0;
  for (int i = 0; i < a.size(); i++) {
    r = r * ain + a[i];
    c.push_back(r / b);
    r %= b;
  }

  int idx = 0;
  while (idx < c.size() && !c[idx]) idx++;
  a = vector<int>(c.begin() + idx, c.end());
}

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    string s;
    scanf("%d%d", &ain, &aout);
    cin >> s;

    vector<int> a;
    for (int i = 0; i < s.size(); i++) {
      if ('0' <= s[i] && s[i] <= '9')
        a.push_back(s[i] - '0');
      else if ('A' <= s[i] && s[i] <= 'Z')
        a.push_back(s[i] - 'A' + 10);
      else
        a.push_back(s[i] - 'a' + 36);
    }

    cout << ain << " " << s << endl;
    cout << aout << " ";

    string res;
    int r;
    while (a.size()) {
      div(a, aout, r);
      res += get(r);
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    puts("");
  }
}