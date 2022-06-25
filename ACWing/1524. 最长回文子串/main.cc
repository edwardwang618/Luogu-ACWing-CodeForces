#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1010, M = 10;
int n, m;
char s[N];
int sa[N], rk[N], y[N], c[N], he[N];
int f[N][M];

void get_sa() {
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

void get_height() {
  for (int i = 1, k = 0; i <= n; i++) {
    if (rk[i] == 1) continue;
    if (k) k--;
    int j = sa[rk[i] - 1];
    while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
    he[rk[i]] = k;
  }
}

void init() {
  for (int i = 1; i <= n; i++) f[i][0] = he[i];
  for (int j = 1; j <= log2(n); j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
}

int query(int l, int r) {
  if (l > r) swap(l, r);
  l++;
  int j = log2(r - l + 1);
  return min(f[l][j], f[r - (1 << j) + 1][j]);
}

int main() {
  cin.getline(s + 1, 1010);
  n = strlen(s + 1), m = 256;
  s[n + 1] = 1;
  for (int i = 1; i <= n; i++) s[n + 1 + i] = s[n - i + 1];
  n = n * 2 + 1;
  s[n + 1] = 0;

  get_sa();
  get_height();

  init();

  int res = 0;
  for (int i = 1; i <= n / 2; i++) {
    res = max(res, query(rk[i], rk[n - i + 1]) * 2 - 1);
    if (i > 1) res = max(res, query(rk[i], rk[n - i + 2]) * 2);
  }

  printf("%d\n", res);
}