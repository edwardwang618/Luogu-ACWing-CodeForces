#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s, p;
  static auto build_ne = [](string& p) {
    int n = p.size() - 1;
    vector<int> ne(p.size());
    for (int i = 2, j = 0; i <= n; i++) {
      while (j && p[i] != p[j + 1]) j = ne[j];
      if (p[i] == p[j + 1]) j++;
      ne[i] = j;
    }
    return ne;
  };
  while (cin >> s) {
    if (s == "#") break;
    cin >> p;
    int n = s.size(), m = p.size();
    s = " " + s;
    p = " " + p;
    auto ne = build_ne(p);
    int res = 0;
    for (int i = 1, j = 0; i <= n; i++) {
      while (j && s[i] != p[j + 1]) j = ne[j];
      if (s[i] == p[j + 1]) j++;
      if (j == m) {
        res++;
        j = 0;
      }
    }
    printf("%d\n", res);
  }
}