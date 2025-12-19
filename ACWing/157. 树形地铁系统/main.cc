#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  auto dfs = [](auto&& self, string &seq, int &u) -> string {
    vector<string> v;
    u++;
    while (seq[u] == '0') v.push_back(self(self, seq, u));
    u++;
    sort(v.begin(), v.end());
    string res = "0";
    for (auto &s : v) res += s;
    return res + "1";
  };

  while (T--) {
    string a, b;
    cin >> a >> b;
    a = "0" + a + "1";
    b = "0" + b + "1";
    int ua = 0, ub = 0;
    if (dfs(dfs, a, ua) == dfs(dfs, b, ub)) puts("same");
    else puts("different");
  }
}