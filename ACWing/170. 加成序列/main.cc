#include <iostream>
#include <cstring>
using namespace std;

const int N = 110;
int a[N];
int n;

bool dfs(int u, int max_d) {
  if (u > max_d) return false;
  
  if (!u) {
    a[u] = 1;
    if (a[u] == n) return true;
    return dfs(u + 1, max_d);
  }
  
  bool vis[N] = {0};
  for (int i = u - 1; i >= 0; i--)
    for (int j = i; j >= 0; j--) {
      int s = a[i] + a[j];
      if (s > n || s <= a[u - 1] || vis[s]) continue;
      vis[s] = true;
      a[u] = s;
      if (s == n) return true;
      if (dfs(u + 1, max_d)) return true;
    }
  
  return false;
}

int main() {
  while (cin >> n, n) {
    int max_d = 0;
    while (!dfs(0, max_d)) max_d++;
    
    for (int i = 0; i <= max_d; i++)
      printf("%d ", a[i]);
    puts("");
  }
    
  return 0;
}