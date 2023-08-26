#include <iostream>
using namespace std;

const int N = 110;
int n, m;
int a[N], b[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> b[i];

  for (int i = 1, j = 1; i <= n || j <= m; )
    if (i > n) printf("%d ", b[j++]);
    else if (j > m) printf("%d ", a[i++]);
    else a[i] <= b[j] ? printf("%d ", a[i++]) : printf("%d ", b[j++]);

  puts("");
}