#include <iostream>
using namespace std;

const int N = 3e6 + 10;
int n, q;
char s[N];
int tr[N][65], idx;
int cnt[N];
int mp['z' + 1];

void add() {
  cnt[0]++;
  int c = 0;
  for (int i = 1; s[i]; i++) {
    int pos = mp[s[i]];
    if (!tr[c][pos]) tr[c][pos] = ++idx;
    c = tr[c][pos];
    cnt[c]++;
  }
}

int query() {
  int c = 0;
  for (int i = 1; s[i]; i++) {
    int pos = mp[s[i]];
    if (!tr[c][pos]) return 0;
    c = tr[c][pos];
  }

  return cnt[c];
}

int main() {
  int cc = 0;
  for (char ch = 'A'; ch <= 'Z'; ch++) mp[ch] = cc++;
  for (char ch = 'a'; ch <= 'z'; ch++) mp[ch] = cc++;
  for (char ch = '0'; ch <= '9'; ch++) mp[ch] = cc++;

  int T;
  scanf("%d", &T);
  while (T--) {
    for (int i = 0; i <= idx; i++)
      for (int j = 0; j <= 'z'; j++)
        tr[i][j] = 0;
    for (int i = 0; i <= idx; i++)
      cnt[i] = 0;
    idx = 0;

    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
      scanf("%s", s + 1);
      add();
    }

    while (q--) {
      scanf("%s", s + 1);
      printf("%d\n", query());
    }
  }
}