#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int n, m;
unordered_map<int, char> to_let;
unordered_map<char, int> to_dig;
vector<int> in, out;

int main() {
  for (char ch = 'A'; ch <= 'Z'; ch++) {
    to_let[ch - 'A' + 10] = ch - 'A' + 'a';
    to_dig[ch] = ch - 'A' + 10;
  }

  cin >> m >> n;
  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    int x;
    if ('A' <= s[i] && s[i] <= 'Z')
      x = to_dig[s[i]];
    else
      x = s[i] - '0';
    in.push_back(x);
  }

  auto get_mod = [&](vector<int>& a, int n) {
    int mod;
    for (int i = 0; i < a.size(); i++) {
      mod = a[i] % n;
      a[i] /= n;
      if (i + 1 < a.size()) a[i + 1] += mod * m;
    }
    int i = 0;
    while (i < a.size() && !a[i]) i++;
    a.erase(a.begin(), a.begin() + i);
    return mod;
  };

  while (in.size()) out.push_back(get_mod(in, n));
  for (int i = out.size() - 1; i >= 0; i--)
    if (0 <= out[i] && out[i] <= 9)
      printf("%d", out[i]);
    else
      putchar(to_let[out[i]]);
}