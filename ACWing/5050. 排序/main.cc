#include <cstring>
#include <iostream>
using namespace std;

char s[210];
int n;
int cnt[26];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    scanf("%s", s + 1);
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) cnt[s[i] - 'a']++;
    for (int i = 1, j = 0; i <= n; i++) {
      while (j < 26 && !cnt[j]) j++;
      s[i] = 'a' + j;
      cnt[j]--;
    }
    printf("%s\n", s + 1);
  }
}