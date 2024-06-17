#include <cstring>
#include <iostream>
using namespace std;

const int N = 5e4 + 10;
char s[N];
int n, q;
int a, b, c, d;
int cnt[26][N];

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) cnt[j][i] = cnt[j][i - 1];
    cnt[s[i] - 'a'][i]++;
  }

  scanf("%d", &q);
  while (q--) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    bool res = true;
    for (int i = 0; i < 26; i++)
      if (cnt[i][b] - cnt[i][a - 1] != cnt[i][d] - cnt[i][c - 1]) {
        res = false;
        break;
      }
    res ? puts("DA") : puts("NE");
  }
}