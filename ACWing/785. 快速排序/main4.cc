#include <iostream>
#include <stack>
#include <tuple>
using namespace std;
using PII = pair<int, int>;

const int N = 100010;
int a[N];

void quick_sort(int l, int r) {
  stack<PII> stk;
  stk.push({l, r});
  while (stk.size()) {
    tie(l, r) = stk.top(); stk.pop();
    if (l >= r) continue;

    int piv = a[l + (r - l >> 1)];
    int i = l, j = r;
    while (i <= j) {
      while (a[i] < piv) i++;
      while (a[j] > piv) j--;
      if (i <= j) swap(a[i++], a[j--]);
    }

    stk.push({l, j}), stk.push({i, r});
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  quick_sort(0, n - 1);
  for (int i = 0; i < n; i++) printf("%d ", a[i]);
}