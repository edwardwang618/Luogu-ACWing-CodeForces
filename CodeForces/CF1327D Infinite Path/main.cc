#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2e5 + 10, INF = N;
int n, a[N], col[N];
bool vis[N];
vector<int> v, fac;
int res;

bool check(int k) {
  for (int s = 0; s < k; s++) {
    int color = col[v[s]];
    bool flag = 1;
    for (int p = s + k; p < v.size(); p += k)
      if (col[v[p]] != color) {
        flag = 0; 
        break;
      }
    if (flag) return true;
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    res = INF;
    memset(vis, 0, sizeof vis);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &col[i]);

    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      vis[i] = 1;
      v.clear();
      int p = a[i];
      v.push_back(i);
      for (; p != i; p = a[p]) v.push_back(p), vis[p] = 1;
      fac.clear();
      int s = v.size();
      for (int k = 1; k <= sqrt(s); k++) {
        if (s % k) continue;
        fac.push_back(k);
        if (k < s / k) fac.push_back(s / k);
      }
      sort(fac.begin(), fac.end());
      
      for (int x : fac) 
        if (check(x)) {
          res = min(res, x);
          break;
        }
    }

    printf("%d\n", res);
  }
}