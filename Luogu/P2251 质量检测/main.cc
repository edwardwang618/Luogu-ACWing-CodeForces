#include <iostream>
#include <deque>
using namespace std;

int n, m;
deque<pair<int, int>> q;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (q.front().first <= i - m) q.pop_front();
    while (q.size() && x <= q.back().second) q.pop_back();
    q.push_back({i, x});
    if (i >= m) printf("%d\n", q.front().second);
  }
}