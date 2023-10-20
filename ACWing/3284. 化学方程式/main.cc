#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
using MPSI = unordered_map<string, int>;

int n;

MPSI dfs(string& s, int& k) {
  MPSI res;
  while (k < s.size() && s[k] != ')') {
    if (s[k] == '(') {
      k++;
      auto mp = dfs(s, k);
      k++;
      int cnt = 1, u = k;
      while (u < s.size() && isdigit(s[u])) u++;
      if (u > k) {
        cnt = stoi(s.substr(k, u - k));
        k = u;
      }
      for (auto& [k, v] : mp) res[k] += v * cnt;
    } else {
      int u = k + 1;
      while (u < s.size() && 'a' <= s[u] && s[u] <= 'z') u++;
      auto elem = s.substr(k, u - k);
      k = u;
      int cnt = 1;
      while (u < s.size() && isdigit(s[u])) u++;
      if (u > k) {
        cnt = stoi(s.substr(k, u - k));
        k = u;
      }
      res[elem] += cnt;
    }
  }
  return res;
}

MPSI work(string s) {
  MPSI res;
  for (int i = 0; i < s.size(); i++) {
    int j = i;
    while (j < s.size() && s[j] != '+') j++;
    auto item = s.substr(i, j - i);
    i = j;
    int cnt = 1, k = 0;
    while (k < item.size() && isdigit(item[k])) k++;
    if (k) cnt = stoi(item.substr(0, k));
    auto mp = dfs(item, k);
    for (auto& [k, v] : mp) res[k] += v * cnt;
  }
  return res;
}

int main() {
  scanf("%d", &n);
  while (n--) {
    string s;
    cin >> s;
    int k = s.find('=');
    work(s.substr(0, k)) == work(s.substr(k + 1)) ? puts("Y") : puts("N");
  }
}