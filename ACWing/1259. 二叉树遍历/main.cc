#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_map>
using namespace std;

const int N = 50;
int l[N], r[N], idx;
string sin, slevel;
unordered_map<char, int> mp;
bool vis[N];

void dfs(int u) {
  if (~u) {
    cout << slevel[u];
    dfs(l[u]);
    dfs(r[u]);
  }
}

int main() {
  memset(l, -1, sizeof l);
  memset(r, -1, sizeof r);
  cin >> sin >> slevel;
  for (int i = 0; i < sin.size(); i++) mp[sin[i]] = i;
  queue<int> q;
  q.push(0);
  while (q.size()) {
    int t = q.front(); q.pop();
    int k = mp[slevel[t]];
    vis[k] = true;
    if (k && !vis[k - 1]) {
      l[t] = ++idx;
      q.push(idx);
    }
    if (k < sin.size() - 1 && !vis[k + 1]) {
      r[t] = ++idx;
      q.push(idx);
    }
  }

  dfs(0);
}