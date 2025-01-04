#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 35;
int n;
struct Node {
  int x;
  int l, r;
} tr[N];
int idx;

int main() {
  scanf("%d", &n);
  vector<int> stk;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    int last = 0;
    while (stk.size() && tr[stk.back()].x > x) {
      last = stk.back();
      stk.pop_back();
    }
    int cur = ++idx;
    tr[cur].x = x;
    tr[cur].l = last;
    if (stk.size()) tr[stk.back()].r = cur;
    stk.push_back(cur);
  }
  int root = stk[0];
  queue<int> q;
  q.push(root);
  while (q.size()) {
    int t = q.front();
    q.pop();
    printf("%d ", tr[t].x);
    if (tr[t].l) q.push(tr[t].l);
    if (tr[t].r) q.push(tr[t].r);
  }
}