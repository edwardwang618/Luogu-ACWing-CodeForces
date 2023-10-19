#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

int bfs(string& start) {
  string end = "12345678x";
  if (start == end) return 0;

  queue<string> q;
  unordered_map<string, int> dist;

  q.push(start);
  dist[start] = 0;

  static int d[] = {1, 0, -1, 0, 1};

  while (!q.empty()) {
    string cur = q.front(); q.pop();

    string tmp = cur;
    int k = cur.find('x');
    int x = k / 3, y = k % 3;
    for (int i = 0; i < 4; i++) {
      int nx = x + d[i], ny = y + d[i + 1];
      if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
        int nk = nx * 3 + ny;
        swap(cur[k], cur[nk]);

        if (cur == end) return dist[tmp] + 1;

        if (!dist.count(cur)) {
          q.push(cur);
          dist[cur] = dist[tmp] + 1;
        }

        swap(cur[k], cur[nk]);
      }
    }
  }

  return -1;
}

int main() {
  string st;
  for (int i = 0; i < 9; i++) {
    char c;
    cin >> c;
    st += c;
  }

  cout << bfs(st) << endl;
}