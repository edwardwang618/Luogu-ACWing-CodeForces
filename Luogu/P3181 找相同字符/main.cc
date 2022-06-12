#include <iostream>
#include <cstring>
using namespace std;

const int N = 4e5 + 10;
int n, m;
char s[N], s2[N];
int sa[N], rk[N], y[N], c[300], he[N];
int stk[N], top;

void get_sa(char s[]) {
  for (int i = 1; i <= n; i++) c[rk[i] = s[i]]++;
  for (int i = 2; i <= m; i++) c[i] += c[i - 1];
  for (int i = n; i; i--) sa[c[rk[i]]--] = i;

  for (int k = 1;; k <<= 1) {
    int num = 0;
    for (int i = n - k + 1; i <= n; i++) y[++num] = i;
    for (int i = 1; i <= n; i++) if (sa[i] > k) y[++num] = sa[i] - k;
    for (int i = 1; i <= m; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) c[rk[i]]++;
    for (int i = 2; i <= m; i++) c[i] += c[i - 1];
    for (int i = n; i; i--) sa[c[rk[y[i]]]--] = y[i];
    swap(rk, y);
    rk[sa[1]] = num = 1;
    for (int i = 2; i <= n; i++)
      rk[sa[i]] = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k] ? num : ++num;
    if (num == n) break;
    m = num;
  }
}

void get_height(char s[]) {
  for (int i = 1, k = 0; i <= n; i++) {
    if (rk[i] == 1) continue;
    if (k) k--;
    int j = sa[rk[i] - 1];
    while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
    he[rk[i]] = k;
  }
}

long calc() {
  long res = 0;
  for (int i = 2; i <= n; i++) {
    while (top && he[stk[top - 1]] >= he[i]) {
      int x = stk[--top];
      int left = x - (top ? stk[top - 1] : 1), right = i - x;
      res += (long) left * right * he[x];
    }
    stk[top++] = i;
  }

  while (top) {
    int x = stk[--top];
    int left = x - (top ? stk[top - 1] : 1), right = n + 1 - x;
    res += (long) left * right * he[x];
  }
  return res;
}

int main() {
  scanf("%s", s + 1);
  long res = 0;
  n = strlen(s + 1), m = 'z';
  int n1 = n;
  get_sa(s);
  get_height(s);
  res -= calc();

  memset(c, 0, sizeof c);

  scanf("%s", s2 + 1);
  n = strlen(s2 + 1), m = 'z';
  get_sa(s2);
  get_height(s2);
  res -= calc();

  n = n1;
  s[++n] = '$';
  for (int k = 1; s2[k]; n++, k++) s[n + 1] = s2[k];
  s[n + 1] = 0;

  memset(c, 0, sizeof c);
  get_sa(s);
  get_height(s);
  res += calc();
  printf("%ld\n", res);
}