#include <iostream>
#include <queue>
using namespace std;

const int N = 30010;
int n, m;
int a[N], b[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i++) scanf("%d", &b[i]);
  priority_queue<int> left;
  priority_queue<int, vector<int>, greater<>> right;
  int i = 0, j = 0;
  while (i < n || j < m) {
    while (j < m && b[j] == i) {
      printf("%d\n", right.top());
      left.push(right.top());
      right.pop();
      j++;
    }

    int x = a[i];
    if (right.empty() || x >= right.top()) right.push(x);
    else {
      left.push(x);
      right.push(left.top());
      left.pop();
    }
    i++;
  }
}