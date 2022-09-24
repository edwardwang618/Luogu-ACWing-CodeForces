#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
int son[N][26], cnt[N], idx;

void insert(string s) {
  int p = 0;
  for (int i = 0; i < s.size(); i++) {
    int u = s[i] - 'a';
    if (!son[p][u]) son[p][u] = ++idx;
    p = son[p][u];
  }

  cnt[p]++;
}

int query(string s) {
  int p = 0;
  for (int i = 0; i < s.size(); i++) {
    int u = s[i] - 'a';
    if (!son[p][u]) return 0;
    p = son[p][u];
  }

  return cnt[p];
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    char op;
    string s;
    cin >> op;
    cin >> s;

    if (op == 'I') insert(s);
    else if (op == 'Q') cout << query(s) << endl;
  }
}