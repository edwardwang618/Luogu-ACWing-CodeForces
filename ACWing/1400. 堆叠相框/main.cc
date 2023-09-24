#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

const int N = 40;
char a[N][N];
int m, n;
unordered_set<char> s;
bool g[N][N];
int ind[N];

void build_edge(char ch, int x1, int x2, int y1, int y2) {
  for (int i : {x1, x2})
    for (int j = y1; j <= y2; j++)
      if (a[i][j] != ch) g[ch - 'A'][a[i][j] - 'A'] = true;

  for (int j : {y1, y2})
    for (int i = x1; i <= x2; i++)
      if (a[i][j] != ch) g[ch - 'A'][a[i][j] - 'A'] = true;

  for (int i = 0; i < 26; i++)
    if (g[ch - 'A'][i]) ind[i]++;
}

void dfs(set<char> st, string& path) {
  if (st.empty()) {
    cout << path << endl;
    return;
  }

  for (char ch : st) {
    path += ch;
    set<char> tmp(st);
    tmp.erase(ch);
    for (char c = 'A'; c <= 'Z'; c++)
      if (s.count(c) && g[ch - 'A'][c - 'A'])
        if (!--ind[c - 'A']) tmp.insert(c);

    dfs(tmp, path);
    for (char c = 'A'; c <= 'Z'; c++)
      if (s.count(c) && g[ch - 'A'][c - 'A']) ind[c - 'A']++;
    path.pop_back();
  }
}

int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++) scanf("%s", a[i] + 1);

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      if (a[i][j] != '.') s.insert(a[i][j]);

  for (char ch : s) {
    int x1 = m + 1, x2 = 0, y1 = n + 1, y2 = 0;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        if (a[i][j] == ch)
          x1 = min(x1, i), x2 = max(x2, i), y1 = min(y1, j), y2 = max(y2, j);

    build_edge(ch, x1, x2, y1, y2);
  }

  string path;
  set<char> st;
  for (char ch = 'A'; ch <= 'Z'; ch++)
    if (s.count(ch) && !ind[ch - 'A']) st.insert(ch);

  dfs(st, path);
}