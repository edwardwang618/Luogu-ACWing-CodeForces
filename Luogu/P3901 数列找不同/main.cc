#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, q;
int close_left[N], last[N], far_left[N];

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    close_left[i] = last[x];
    last[x] = i;
    far_left[i] = max(close_left[i], far_left[i - 1]);
  }

  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    far_left[r] < l ? puts("Yes") : puts("No");
  }
}