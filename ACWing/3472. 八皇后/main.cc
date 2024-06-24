#include <iostream>
using namespace std;

bool col[10], diag[20], udiag[20];
int idx;
string res[100];

void dfs(int u, string& s) {
  if (u == 8) {
    res[++idx] = s;
    return;
  }
  for (int i = 0; i < 8; i++)
    if (!col[i] && !diag[7 - i + u] && !udiag[i + u]) {
      col[i] = diag[7 - i + u] = udiag[i + u] = true;
      s += to_string(i + 1);
      dfs(u + 1, s);
      col[i] = diag[7 - i + u] = udiag[i + u] = false;
      s.pop_back();
    }
}

int main() {
  string s;
  dfs(0, s);
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    cout << res[n] << endl;
  }
}