#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
int n, k, a[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {  
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n, greater<int>());
    long res = 0;
    for (int i = 1; i <= k + 1; i++) res += a[i];
    printf("%ld\n", res);
  }  
}