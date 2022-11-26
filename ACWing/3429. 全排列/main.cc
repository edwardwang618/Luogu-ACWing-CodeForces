#include <iostream>
using namespace std;

bool vis[7];
string s, t;

void dfs(int u) {
  if (u == s.size()) cout << t << endl;
  for (int i = 0; i < s.size(); i++) {
    if (vis[i]) continue;
    t[u] = s[i];
    vis[i] = true;
    dfs(u + 1);
    vis[i] = false;
  }
}

int main() {
  cin >> s;
  t.resize(s.size());
  dfs(0);
}