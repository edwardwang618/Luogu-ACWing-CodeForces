#include <iostream>
#include <deque>

#define x first
#define y second

using namespace std;

const int INF = 1e9;
int n, m;
deque<pair<int, int>> dq;

int main() {
  scanf("%d%d", &n, &m);
  int res = -INF;
  dq.push_back({0, 0});
  for (int i = 1, s = 0; i <= n; i++) {
    int a;
    scanf("%d", &a);
    s += a;
    if (dq.size() && i - dq.front().x > m) dq.pop_front();
    res = max(res, s - dq.front().y);
    while (dq.size() && dq.back().y >= s) dq.pop_back();
    dq.push_back({i, s});
  }

  printf("%d\n", res);
}