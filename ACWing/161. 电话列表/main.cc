#include <cstring>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, son[N][10], cnt[N];
string str[N];
int idx;

void insert(string &s) {
  int p = 0;
  for (char ch : s) {
    int u = ch - '0';
    if (!son[p][u]) son[p][u] = ++idx;
    p = son[p][u];
    cnt[p]++;
  }
}

bool query(string &s) {
  int p = 0;
  for (char ch : s) {
    int u = ch - '0';
    p = son[p][u];
    if (cnt[p] == 1) return true;
  }

  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(son, 0, sizeof son);
    memset(cnt, 0, sizeof cnt);
    idx = 0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      cin >> str[i];
      insert(str[i]);
    }

    bool flag = true;
    for (int i = 1; i <= n; i++)
      if (!query(str[i])) {
        flag = false;
        break;
      }

    if (flag) puts("YES");
    else puts("NO");
  }
}