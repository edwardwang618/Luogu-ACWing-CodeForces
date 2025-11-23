#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int bfs(string& st) {
  string ed = "12345678x";
  if (st == ed) return 0;
  int d[] = {1, 0, -1, 0, 1};
  queue<string> q;
  unordered_set<string> vis;
  q.push(st);
  vis.insert(st);
  int res = 0;
  while (q.size()) {
    res++;
    for (int i = q.size(); i; i--) {
      auto t = q.front(); q.pop();
      int k = t.find('x');
      int x = k / 3, y = k % 3;
      string tmp = t;
      for (int j = 0; j < 4; j++) {
        int nx = x + d[j], ny = y + d[j + 1], nk = nx * 3 + ny;
        if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
          swap(tmp[k], tmp[nk]);
          if (!vis.count(tmp)) {
            if (tmp == ed) return res;
            vis.insert(tmp);
            q.push(tmp);
          }
          swap(tmp[k], tmp[nk]);
        }
      }
    }
  }

  return -1;
}

int main() {
  string st;
  char ch;
  while (scanf("%c", &ch) != EOF) if (ch == 'x' || isdigit(ch)) st += ch;

  printf("%d\n", bfs(st));
}