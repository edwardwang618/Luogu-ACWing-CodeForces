#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 2e5 + 10;
int n, m;
int b[N], c[N];

int main() {
  scanf("%d", &n);
  unordered_map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    mp[a]++;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &c[i]);

  int res = -1, max_yuyin = -1, max_zimu = -1;
  for (int i = 1; i <= m; i++) {
    int yuyin = mp[b[i]];
    if (yuyin > max_yuyin)
      res = i, max_yuyin = yuyin, max_zimu = mp[c[i]];
    else if (yuyin == max_yuyin) {
      if (mp[c[i]] > max_zimu) res = i, max_zimu = mp[c[i]];
    }
  }

  printf("%d\n", res);
}