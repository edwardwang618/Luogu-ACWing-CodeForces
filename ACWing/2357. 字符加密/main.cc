#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e5 + 10;
int n, m;
char s[N];
int sa[N], rk[N], y[N], c[N];

void get_sa() {
  for (int i = 1; i <= n; i++) c[rk[i] = s[i]]++;
  for (int i = 2; i <= m; i++) c[i] += c[i - 1];
  for (int i = 1; i <= n; i++) sa[c[rk[i]]--] = i;

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

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1), m = 'z';
  for (int i = 1; i < n; i++) s[i + n] = s[i];
  int n1 = n;
  n = n * 2 - 1;
  get_sa();

  for (int i = 1; i <= n; i++)
    if (n - sa[i] + 1 >= n1)
      putchar(s[sa[i] + n1 - 1]);
}