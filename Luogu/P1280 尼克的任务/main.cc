#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4 + 10;
int n, k;
vector<int> a[N];
int f[N];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x].push_back(y);
  }

  for (int i = n; i >= 1; i--) {
    if (a[i].size()) {
      for (int len : a[i])
        f[i] = max(f[i], f[i + len]);
    } else f[i] = f[i + 1] + 1;
  }

  printf("%d\n", f[1]);
}